#!/bin/bash

# Votre pipeline actuel pour traiter les données
cat data/data.csv | awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $6); print $1 ";" $6}' | \
  awk -F ';' 'NR > 1 {count_prenom[$1]++; prenom[$1]=$2} END {for (p in prenom) print p ";"prenom[p]}' | \
  awk -F ';' 'NR > 1 {count[$2]++} END {for (p in count) print p ";" count[p]}' | \
  sort -t';' -k2 -n -r | head -n 10 | awk -F';' '{print $1 ";" $2}' > temp/nombre_trajets_par_prenom_tries_final.txt

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
plot 'temp/nombre_trajets_par_prenom_tries_final.txt' using (\$0-0.3):2:xtic(1) with boxes notitle
EOF

# Incliner l'image à 90 degrés avec ImageMagick
convert -rotate 90 histogramme_vertical.png histogramme_incline.png

# Ouvrir l'image inclinée
xdg-open histogramme_incline.png

