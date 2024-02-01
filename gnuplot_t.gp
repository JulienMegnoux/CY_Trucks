set terminal pngcairo enhanced font 'arial,10' size 800, 600
set output 'images/histogramme.png'

unset errorbars
set datafile separator ','
set grid nopolar
set grid xtics mxtics ytics mytics noztics nomztics nortics nomrtics \
 nox2tics nomx2tics noy2tics nomy2tics nocbtics nomcbtics
set grid layerdefault lt 0 linecolor 0 linewidth 0.500, lt 0 linecolor 0 linewidth 0.500
set style data histogram
set style histogram clustered
set style fill solid
set xtics rotate by -45
set ytics norangelimit autofreq
set format x "" # Supprime les étiquettes de l'axe x pour les valeurs de la 1ère colonne
set title "Histogramme des valeurs de la 2ème colonne"
set xlabel "Villes"
set ylabel "Valeurs"
set boxwidth 0.8
set key autotitle columnhead
set xrange [ * : * ] noreverse writeback

# Dernier fichier de données tracé: "temp/villes.txt"
plot 'temp/villes.txt' using (column(0)):2:xticlabels(1) with boxes title "Valeurs"

