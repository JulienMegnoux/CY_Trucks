#!/bin/bash



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



# permet d'executer nos options 
function myhelp()
{
echo "veuillez tapez ./shell options"
echo "options :| -d1 | -d2 | -l |"
}
if [ $# = 1 ]; then


	if [ $1 == "-d1" ]; then
		#pretraitement
		echo "option d1"
		./Option_D1.sh
	elif [ $1 == "-d2" ]; then
		#pretraitement
		echo "option d2"
		./Option_D2.sh
	elif [ $1 == "-l" ]; then
		#pretraitement
		echo "option l"
		./Option_L.sh
	
	else 
		myhelp
	
	fi 

else
	myhelp

fi
