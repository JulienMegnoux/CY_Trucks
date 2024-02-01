set terminal pngcairo enhanced font 'arial,10' size 800, 600
set output 'images/graphique.png'

unset errorbars
set datafile separator ','
set grid nopolar
set grid xtics mxtics ytics mytics noztics nomztics nortics nomrtics \
 nox2tics nomx2tics noy2tics nomy2tics nocbtics nomcbtics
set grid layerdefault lt 0 linecolor 0 linewidth 0.500, lt 0 linecolor 0 linewidth 0.500
set style data boxes  # Utiliser le style boxes pour afficher les identifiants dans l'ordre
set xtics rotate by -60
set ytics norangelimit logscale autofreq
set format x "" # Supprime les étiquettes de l'axe x pour les valeurs de la 1ère colonne
set title "Option -s Distance = f(Route)"
set xlabel "Routes ID"
set xrange [ * : * ] noreverse writeback
set x2range [ * : * ] noreverse writeback
set ylabel "Distance (Km)"
set yrange [1:1000] noreverse writeback
Shadecolor = "#80E0A080"

# Créer une variable avec un index croissant pour chaque ligne
index_column = 0
increment_index = 1
set style fill solid
# Dernier fichier de données tracé: "temp/vamos.txt"
plot 'temp/vamos.txt' using ($0+increment_index):3:4 with filledcurve fc rgb Shadecolor title "Distance max/min", '' using ($0+increment_index):6:xticlabels(1) with boxes smooth mcspline lw 2 title "Distance average"

