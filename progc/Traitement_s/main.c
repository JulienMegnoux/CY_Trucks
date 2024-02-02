#include "AVLs.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour lire le fichier et insérer les données dans l'arbre1
void insererDepuisFichier(pArbre *arbre, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int idtrajet;
    float distance;

    // Lecture des données du fichier et insertion dans l'arbre1
    while (fscanf(fichier, "%d;%f", &idtrajet, &distance) == 2) {
        int h = 0;
        *arbre = insertionT(*arbre, idtrajet, distance, &h);
    }

    // Fermeture du fichier
    fclose(fichier);
}

void displayArbre(pArbre ArbreD){
	if(ArbreD == NULL){
	exit(15);
	}
	printf("[%02d]\n",ArbreD->nb);
}

void parcoursInfixeInverse(pArbre ArbreD) {
    if (ArbreD != NULL) {
        parcoursInfixeInverse(ArbreD->fd);
        displayArbre(ArbreD);
        parcoursInfixeInverse(ArbreD->fg);
    }
}


int main() {
	
    pArbre ArbreT = NULL;  // Initialisation de l'arbre
    pArbre ArbreD = NULL;  // Initialisation de l'arbre

    // Insérer les données depuis le fichier dans ArbreT
    insererDepuisFichier(&ArbreT, "resultat.txt");

    // Copier et insérer les données depuis ArbreT dans ArbreD
    ArbreD = CopieEtInsertionD(ArbreT, ArbreD);

 

   // Affichage de l'arbre ArbreD
    afficherArbre2(ArbreD);
    printf("\n");
    
    // Libération de la mémoire si nécessaire...

    return 0;
}

