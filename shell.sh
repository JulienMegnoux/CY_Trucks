#!/bin/bash


# Enregistrez le temps de début
start_time=$(date +%s)

# Spécifiez le chemin de l'exécutable en C
executable_path="$HOME/Documents/Projet/exec"

# Vérifiez si le fichier exécutable existe et est exécutable
if [ -x "$executable_path" ]; then
    echo "L'exécutable en C existe et est exécutable."
else
    # Le fichier exécutable n'existe pas ou n'est pas exécutable, essayez de le compiler
    echo "Compilation de l'exécutable en C..."

    # Spécifiez le chemin du code source C
    source_path="$HOME/Documents/Projet/CY_Trucks/progc/progc.c"

    # Spécifiez le chemin de sortie de la compilation
    output_path="$HOME/Documents/Projet/CY_Trucks/exec"

    # Compilez le code source en un exécutable
    gcc "$source_path" -o "$output_path"

    # Vérifiez si la compilation s'est bien déroulée
    if [ $? -eq 0 ]; then
        echo "La compilation s'est bien déroulée. L'exécutable a été créé."
    else
        echo "La compilation a échoué. Veuillez vérifier votre code source."
        exit 1  # Quitte le script avec un code d'erreur
    fi
fi





# Spécifiez le chemin du dossier "temp"
temp_folder="$HOME/Documents/Projet/CY_Trucks/temp"

# Spécifiez le chemin du dossier "images"
images_folder="$HOME/Documents/Projet/CY_Trucks/images"

# Vérifiez si le dossier "images" existe
if [ -d "$images_folder" ]; then
    echo "Le dossier 'images' existe."
else
    echo "Le dossier 'images' n'existe pas. Création du dossier..."
    mkdir -p "$images_folder"

    # Vérifiez si la création du dossier s'est bien déroulée
    if [ $? -eq 0 ]; then
        echo "Le dossier 'images' a été créé avec succès."
    else
        echo "La création du dossier 'images' a échoué. Veuillez vérifier les permissions."
        exit 1  # Quitte le script avec un code d'erreur
    fi
fi

# Vérifiez si le dossier "temp" existe
if [ -d "$temp_folder" ]; then
    echo "Le dossier 'temp' existe. Vidage du dossier..."

    # Supprime récursivement le contenu du dossier "temp"
    rm -f "$temp_folder/*"

    # Vérifiez si la suppression s'est bien déroulée
    if [ $? -eq 0 ]; then
        echo "Le dossier 'temp' a été vidé avec succès."
    else
        echo "Le vidage du dossier 'temp' a échoué. Veuillez vérifier les permissions."
        exit 1  # Quitte le script avec un code d'erreur
    fi
else
    echo "Le dossier 'temp' n'existe pas. Création du dossier..."
    mkdir -p "$temp_folder"

    # Vérifiez si la création du dossier s'est bien déroulée
    if [ $? -eq 0 ]; then
        echo "Le dossier 'temp' a été créé avec succès."
    else
        echo "La création du dossier 'temp' a échoué. Veuillez vérifier les permissions."
        exit 1  # Quitte le script avec un code d'erreur
    fi
fi





#option d1




# Utiliser Awk pour extraire les colonnes des prénoms (sixième position) et des numéros de trajet (première position)
cat data/data.csv | awk -F ';' 'NR > 1 {gsub(/"/, "", $1); gsub(/"/, "", $6); print $1 ";" $6}' | awk -F ';' 'NR > 1 {count_prenom[$1]++; prenom[$1]=$2} END {for (p in prenom) print p ";"prenom[p]}' | awk -F ';' 'NR > 1 {count[$2]++} END {for (p in count) print p ";" count[p]}' | sort -t';' -k2 -n -r temp/nombre_trajets_par_prenom_tries.txt | head -n 10 | awk -F';' '{print $1 ";" $2}' > temp/nombre_trajets_par_prenom_tries_final.txt

# Utiliser Awk pour compter le nombre de trajets par prénom et stocker le résultat dans un fichier temporaire





# afficher les 10 premiers, puis extraire les 2ème et 3ème colonnes









# Enregistrez le temps de fin
end_time=$(date +%s)

# Calculez la différence pour obtenir le temps d'exécution
execution_time=$((end_time - start_time))

# Affichez le temps d'exécution
echo "Le script a mis $execution_time secondes à s'exécuter."

