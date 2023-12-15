set terminal pngcairo enhanced font 'arial,10'
set output 'histogramme_horizontal.png'

set style fill solid
set boxwidth 0.2

set xlabel 'Fréquence'
set ylabel 'Catégories'

set datafile separator ';'
set xtics rotate by 45 offset -0.8,-1.8

plot 'temp/nombre_trajets_par_prenom_tries.txt' using :xtic(1):ytic(2) with boxes notitle 



