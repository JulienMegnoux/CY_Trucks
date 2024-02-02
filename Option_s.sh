#!/bin/bash
cat data/data.csv |awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $5); print $1 ";" $5}'> resultat.txt
gcc -o exec progc/Traitement_s/main.c
./exec | head -50 > temp/vamos.txt
gnuplot gnuplot_s.gp
xdg-open images/graphique.png


