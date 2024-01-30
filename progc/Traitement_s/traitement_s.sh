#!/bin/bash
cat data.csv |awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $5); print $1 ";" $5}'>resultat.txt
gcc -o exec test_s.c
./exec
