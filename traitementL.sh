# Extraire les identifiants de chaque trajet et leurs kilomètres
awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $5); print $1 ";" $5}' data/data.csv > temp/donnees.txt

# Calculer la distance totale de chaque trajet
awk -F ';' 'NR > 1 {
    id_trajet = $1;
    distance = $5;
    
    # Utiliser un tableau associatif pour stocker la distance totale par identifiant de trajet
    total_distance[id_trajet] += distance;
} END {
    for (id in total_distance) {
        print id ";" total_distance[id];
    }
}' temp/donnees_trajets.txt > temp/distance_totale_trajets.txt

# Trier les résultats par distance en km, en ordre décroissant, puis conserver les 10 premiers
sort -t';' -k2 -n -r temp/distance_totale_trajets.txt | head -n 10 > temp/top_10_trajets.txt

# Créer un graphique d'histogramme vertical avec gnuplot
gnuplot -persist <<EOF
set terminal png
set output "histogramme_trajets.png"
set xlabel "Identifiant du trajet"
set ylabel "Distance en km"
set title "Les 10 trajets les plus longs"
set boxwidth 0.5
set style fill solid
plot "temp/top_10_trajets.txt" using 2:xticlabels(1) with boxes
EOF


