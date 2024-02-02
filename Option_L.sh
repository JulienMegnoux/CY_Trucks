#!/bin/bash
start_time=$(date +%s)

# Calculer la distance totale de chaque trajet
awk -F ';' 'NR > 1 {
gsub(/"/, "", $1); 
gsub(/"/, "", $5);
		id_trajet = $1;
		distance = $5; 
		total_distance[id_trajet] += distance;
} END {
		for (id in total_distance) {
				print id ";" total_distance[id];
		}
}' data/data.csv | sort -t';' -k2 -n -r | head -n 10 > temp/top_10_trajets.txt


#creer un graphique d'historigramme vertical avec gnuplot
gnuplot <<EOF
set terminal pngcairo enhanced font 'arial,10'
set output "histogramme_vertical.png"

set style fill solid
set boxwidth 0.5

set xlabel "Identifiant du trajet"
set ylabel "Distance en km"

set datafile separator ';'
set title "Les 10 trajets les plus longs"

plot "temp/top_10_trajets.txt" using (\$0-0.3):2:xtic(1) with boxes notitle
EOF

end_time=$(date +%s)
echo "Le script a mis $((end_time - start_time))secondes"


# Ouvrir l'image inclinée
xdg-open images/histogramme_vertical.png
