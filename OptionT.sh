#!/bin/bash

# Extraction des données du fichier CSV
awk -F ';' 'NR > 1 {
    key1 = $2 " " $3 " " $4
    key2 = $2 " " $4 " " $3

    # Compter les villes de départ
    if (!seen[key1]++) {
        count_villes[$3]++;
    }

   
    if (!seen[key2]++) {
        count_villes[$4]++;
    }

 
    # ajuster le compteur
    if ($2 == prev_num && $4 == prev_ville) {
        count_villes[$4]--;
    }

    prev_num = $2
    prev_ville = $3
}
END {
    for (ville in count_villes) {
        print ville, count_villes[ville];
    }
}' data/data.csv | sort > temp/ville_counts.txt

# Afficher le fichier avec le compte des villes
cat temp/ville_counts.txt

