#!/bin/bash
cat data/data.csv |awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $5); print $1 ";" $5}'> progc/Traitement_s/resultat.txt

