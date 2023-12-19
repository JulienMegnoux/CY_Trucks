set terminal pngcairo enhanced font 'arial,10'
set output 'histogramme_horizontal.png'

set style fill solid
set boxwidth 0.2

set xlabel 'Nombre de trajets'
set ylabel 'Prénom'

set datafile separator ';'
set xtics rotate by 45 offset -0.8,-1.8

plot 'temp/nombre_trajets_par_prenom_tries.txt' using :xtic(1):ytic(2) with boxes notitle 






#CA MAAAAAAAAAAAAAAArche
# Utiliser Awk pour extraire les colonnes des prénoms (sixième position) et des numéros de trajet (première position)
awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $6); print $1 ";" $6}' data/data.csv > temp/donnees.txt

# Utiliser Awk pour compter le nombre de trajets par prénom et stocker le résultat dans un fichier temporaire
awk -F ';' 'NR > 1 {count_prenom[$1]++; prenom[$1]=$2} END {for (p in prenom) print p ";"prenom[p]}' temp/donnees.txt > temp/nombre_trajets_par_prenom.txt

awk -F ';' 'NR > 1 {count[$2]++} END {for (p in count) print p ";" count[p]}' temp/nombre_trajets_par_prenom.txt > temp/nombre_trajets_par_prenom_tries.txt


# afficher les 10 premiers, puis extraire les 2ème et 3ème colonnes
sort -t';' -k2 -n -r temp/nombre_trajets_par_prenom_tries.txt | head -n 10 | awk -F';' '{print $1 ";" $2}' > temp/nombre_trajets_par_prenom_tries_final.txt
