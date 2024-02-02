#!/bin/bash


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
echo "options :| -d1 | -d2 | -l | -s | -t |"
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
	elif [ $1 == "-l" ]; then
		#pretraitement
		echo "option s"
		./Option_s.sh
  	elif [ $1 == "-l" ]; then
		#pretraitement
		echo "option t"
		./Option_t.sh
	else 
		myhelp
	
	fi 

else
	myhelp

fi	
