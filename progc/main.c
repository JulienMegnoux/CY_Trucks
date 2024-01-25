/////////////////////////////////////////////////////////// ATENTION /////////////////////////////////////////////////////////////////////
- dans mon 2e AVL qui trie par rapport au distance total parcouru dans ma fonction insertionD je n'ai pas gerer le cas ou la distance total parcouru est égal (a voir si besoin de gerer ce cas la)
- bien regarder par quoi il faut trié pour les 50 plus grande valeur et faire quelque modification si nécessaire
- il manque une fonction qui lit les 50 plus grande valeur de mon 2e arbre et écris les valeur dans un fichier texte
- quand je codais sur replit il me disait "multiple definition of (nomfonction)" il me faisait ca sur toute mes fonction donc je pense avoir une erreur dans mes include mais je suis pas sur





------------------------------------------	main.c	------------------------------------------
#include "AVLs.h"
#include "AVLs.c"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour lire le fichier et insérer les données dans l'arbre1
  void insererDepuisFichier(pArbre arbre, const char *nomFichier) {
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
          arbre = insertionT(arbre, idtrajet, distance, &h);
      }

      // Fermeture du fichier
      fclose(fichier);
  }


int main() {
    pArbre ArbreT = NULL;  // Initialisation de l'arbre
    pArbre ArbreD = NULL;  // Initialisation de l'arbre

    insererDepuisFichier(ArbreT, "test.txt");
    CopieEtInsertionD(ArbreT, ArbreD);
    afficherArbre(ArbreT);
    afficherArbre2(ArbreD);


  
    return 0;
}

