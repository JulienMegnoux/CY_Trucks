#!/bin/bash

# Enregistrez le temps de début
start_time=$(date +%s)

# Utiliser Awk pour extraire les colonnes des prénoms (sixième position) et des numéros de trajet (première position),
# compter le nombre de trajets par prénom, trier et sélectionner les 10 premiers, puis extraire les 2ème et 3ème colonnes

awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $6); total[$6]+=$5} END {for (p in total) print total[p], p}' data/data.csv | sort -rn | awk 'NR <= 10 {print $2 ";" $1}' > total_par_prenom_tries.txt

# Enregistrez le temps de fin
end_time=$(date +%s)

# Affichez le temps d'exécution
echo "Le script a mis $((end_time - start_time)) secondes à s'exécuter."

#gnuplot

gnuplot <<EOF
set terminal pngcairo enhanced font 'arial,10'
set output 'histogramme_verticald2.png'

set style fill solid
set boxwidth 0.3  # Ajustez la largeur des barres selon vos préférences

set ylabel 'Distance totale'
set xlabel 'Prénom'

set datafile separator ';'
set xtics rotate by 90 offset -0.8,-1.8
set ytics rotate by 90 offset -0.8,-1.8

# Utilisez le format de données 'xtic(1)' pour spécifier les prénoms en tant que libellés de l'axe des x
# Utilisez 'rotate by' pour faire	 pivoter les étiquettes
set yrange [0:250]

# Utilisez '($0-0.3)':2 pour décaler les barres vers la gauche
plot 'total_par_prenom_tries.txt' using (\$0-0.3):2:xtic(1) with boxes notitle
EOF

# Incliner l'image à 90 degrés avec ImageMagick
convert -rotate 90 histogramme_verticald2.png histogramme_incline.png

# Ouvrir l'image inclinée
xdg-open histogramme_incline.png
