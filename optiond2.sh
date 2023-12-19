#!/bin/bash
#echo Hello World
# Utiliser Awk pour extraire les colonnes des conducteurs (quatrième position) et des distances (cinquième position)
#modifier la position selon fichier excel 

awk -F ';' 'NR > 1 {gsub(/"/, "", $4); gsub(/"/, "", $5); print $4 ";" $5}' | awk -F ';' '{distance[$1] += $2} END {for (d in distance) print d ";" distance[d]}' | sort -t';' -k2 -n -r temp/distance_totale_conducteurs.txt | head -n 10 




# Afficher le résultat
cat temp/top_10_distances_conducteurs.txt
