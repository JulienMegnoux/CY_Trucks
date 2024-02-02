#!/bin/bash

# Enregistrez le temps de début
start_time=$(date +%s)

# Utiliser Awk pour extraire les colonnes des prénoms (sixième position) et des numéros de trajet (première position),
# compter le nombre de trajets par nom complet du conducteur (prénom et nom avec espace),
# trier et sélectionner les 10 premiers, puis extraire les 2ème et 3ème colonnes


awk -F ';' 'NR > 1 {gsub(/"/, "", $1); full_name=$6" "$7; total[full_name]+=$5} END {for (p in total) print p ";" total[p]}' data/data.csv | sort -t';' -k2 -n -r | head -n 10 > temp/total_par_nom_complet_tries.txt

# Enregistrez le temps de fin
end_time=$(date +%s)

# Affichez le temps d'exécution
echo "Le script a mis $((end_time - start_time)) secondes à s'exécuter."

#gnuplot

gnuplot <<EOF



# Paramètres de sortie
set terminal pngcairo size 1000,800 enhanced font 'Arial,10'
set output 'images/histogramme_verticald2.png'

# Paramètres du graphique
set size 0.95,1
set label rotate by 90 "HISTOGRAMME DE TRAITEMENT -d2" at screen 0.015, 0.5 center offset 0.3
set xlabel 'CONDUCTEURS '
set ylabel 'DISTANCE TOTALE (en km)'
set xtic rotate by 90 offset 0,-9
set xlabel rotate by 180 offset 0,-9
set ylabel offset 5
set ytic offset 3,0.60
set yrange [0:200000]
set ytic rotate by 90
set ytics 0, 40000, 200000
set format y "%g km"  # Format pour l'axe des ordonnées
set style histogram rowstacked
set style fill solid border -1
set boxwidth 0.5
unset key

# Tracé du graphique
set datafile separator ';'
plot 'temp/total_par_nom_complet_tries.txt' using 2:xtic(1) with boxes lc rgb 'violet' title 'Distance'


EOF

convert -rotate 90 images/histogramme_verticald2.png images/histogramme_incline.png

# Ouvrir l'image inclinée
xdg-open images/histogramme_incline.png
