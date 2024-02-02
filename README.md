Projet CY-Trucks : Projet de Gestion de Donnnées pour une Société de Transport Routier
    Projet Informatique III de l'année 2023-2024 à CY-Tech.
Ce projet a pour but d'analyser les données massives des trajets routiers afin de générer des graphiques.

Table des matières : 
    I. Structure du Projet
    II. Compilation et utilisation du projet
    III. Traitements disponibles
  

  

I. Structure du projet :
    Le projet est dans le github CY-Trucks.
    data: Ce dossier contiendra le fichier CSV d'entrée avec les données des trajets routiers.
    progc: Le programme C et ses fichiers associés (makefile, exécutable, etc.) seront situés ici.
    images: Les graphiques générés, au format PNG, seront stockés dans ce dossier. 
    temp: Les fichiers intermédiaires nécessaires au fonctionnement de l'application seront placés ici.
    demo: Les résultats d'exécutions précédentes seront stockés dans ce dossier.




II. Compilation et utilisation du projet :
    Avant tout, il est nécessaire d'exécuter la commande chmod pour garantir les permissions nécessaires comme ceci :
                    '''bash
                    chmod 777 fichier
            
    Afin de compiler correctement le programme il faudra être sous Linux basé sur OS. 
    compiler selon les commandes présentes dans le makefile.
    Afin d'utiliser correctement le projet il faudra en amont installer Gnuplot pour pouvoir utiliser Gnuplot.
    Afin d'utiliser le projet il faudra mettre le fichier.csv dans le dossier data.
    Pour choisir un traitement, vous devrez passer la lettre du traitement en argument (les différents arguments seront détaillés plus loin).


III. Traitements disponibles :
pour les utiliser : faire ./shell.sh -traitements
traitements :
    "-d1" - conducteurs avec le plus de trajets
    "-d2" - top 10 conducteurs avec la plus grande distance
    "-l" - les 10 trajets les plus longs
    "-t" - les 10 villes les plus traversées
    "-s" - statistiques sur les étapes
    "-h" -help : indique tout les arguments existants et leur traitement associé.
    exemple pour afficher les conducteur avec le plus de trajtes : faire ./shell.sh -d1

