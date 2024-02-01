#!/bin/bash
gcc -o exec progc/Traitement_t/optiont.c
./exec > temp/villes.txt
gnuplot gnuplot_t.gp
xdg-open images/histogramme.png
