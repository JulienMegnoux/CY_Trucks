#!/bin/bash
#echo Hello World
# Utiliser Awk pour extraire les colonnes des conducteurs (quatrième position) et des distances (cinquième position)
#modifier la position selon fichier excel 

# Utiliser Awk pour extraire les colonnes des prénoms (sixième position) et des numéros de trajet (première position)
awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $6); print $6 ";" $5}' | \

# Utiliser Awk pour compter le nombre de trajets par prénom et stocker le résultat dans un fichier temporaire
awk -F ';' 'NR > 0  {total[$1]+=$2} END {for (p in total) print p ";" total[p] }' | \
# afficher les 10 premiers, puis extraire les 2ème et 3ème colonnes
sort -t';' -k2 -n -r total_par_prenom.txt | head -n 10 | awk -F';' '{print $2 ";" $3}' > temp/top_10_distances_conducteurs.txt

# Afficher le résultat
#cat temp/top_10_distances_conducteurs.txt


# Script Gnuplot
gnuplot <<EOF
set terminal pngcairo enhanced font 'arial,10'
set output 'histogramme_vertical.png'

set style fill solid
set boxwidth 0.3  # Ajustez la largeur des barres selon vos préférences

set ylabel 'Nombre de trajets'
set xlabel 'Prénom'

set datafile separator ';'
set xtics rotate by 90 offset -0.8,-1.8
set ytics rotate by 90 offset -0.8,-1.8

# Utilisez le format de données 'xtic(1)' pour spécifier les prénoms en tant que libellés de l'axe des x
# Utilisez 'rotate by' pour faire	 pivoter les étiquettes
set yrange [0:250]

# Utilisez '($0-0.3)':2 pour décaler les barres vers la gauche
plot 'temp/top_10_distances_conducteurs.txt' using (\$0-0.3):2:xtic(1) with boxes notitle
EOF

# Incliner l'image à 90 degrés avec ImageMagick
convert -rotate 90 histogramme_vertical.png histogramme_incline.png

# Ouvrir l'image inclinée
xdg-open histogramme_incline.png
