#!/bin/bash

&& choisir les options
echo "Voici les différentes options des traitements possibles :"
echo "1 --> D1"
echo "2 --> D2"
echo "3 --> L"
echo "4 --> T"
echo "5 --> S"

read -p "Entrez le numéro de votre choix : " choix

case $choix in
    1)
        ./traitementD1.sh
        ;;
    2)
        ./traitementD2.sh
        ;;
    3)
        ./traitementL.c
        ;;
    4)
        ./traitementT.c
        ;;
    5)
        ./traitementS.c
        ;;
    *)
        echo "Option invalide."
        ;;
esac
