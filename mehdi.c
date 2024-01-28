#include <stdio.h>
#include <stdlib.h>

// Structure pour stocker les données triées
typedef struct {
    int id;
    float min, max, moy, diff;
} DonneeTriee;

// Structure de l'arbre AVL
typedef struct avl {
    int id;
    float distance_min;
    float distance_max;
    float distance_moy;
    float diff;
    struct avl *fd;
    struct avl *fg;
    int equilibre;
} Avl;

// Fonction pour compter les nœuds dans l'arbre AVL
int compterNoeuds(Avl *a) {
    if (a == NULL) {
        return 0;
    } else {
        return 1 + compterNoeuds(a->fg) + compterNoeuds(a->fd);
    }
}

// Fonction pour créer un nouveau nœud AVL
Avl *creerAvl(int id, float min, float max, float moy, float diff) {
    Avl *new = malloc(sizeof(Avl));
    if (new == NULL) {
        fprintf(stderr, "Erreur d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }
    new->id = id;
    new->distance_min = min;
    new->distance_max = max;
    new->distance_moy = moy;
    new->diff = diff;
    new->fd = NULL;
    new->fg = NULL;
    new->equilibre = 0;
    return new;
}

// Fonction pour effectuer une rotation gauche
Avl *rotationG(Avl *a) {
    int eq_pivot;
    int eq_a;
    Avl *pivot;
    pivot = a->fd;
    a->fd = pivot->fg;
    pivot->fg = a;
    eq_a = a->equilibre;
    eq_pivot = pivot->equilibre;
    a->equilibre = eq_a - (eq_pivot > 0 ? eq_pivot : 0) - 1;
    pivot->equilibre = (eq_a > 2 ? eq_a - 2 : (eq_a + eq_pivot - 2 > eq_pivot - 1 ? eq_a + eq_pivot - 2 : eq_pivot - 1));
    a = pivot;
    return a;
}

// Fonction pour effectuer une rotation droite
Avl *rotationD(Avl *a) {
    int eq_pivot;
    int eq_a;
    Avl *pivot;
    pivot = a->fg;
    a->fg = pivot->fd;
    pivot->fd = a;
    eq_a = a->equilibre;
    eq_pivot = pivot->equilibre;
    a->equilibre = eq_a - (eq_pivot < 0 ? eq_pivot : 0) + 1;
    pivot->equilibre = (eq_a < -2 ? eq_a + 2 : (eq_a + eq_pivot + 2 > eq_pivot + 1 ? eq_a + eq_pivot + 2 : eq_pivot + 1));
    a = pivot;
    return a;
}

// Fonction pour effectuer une double rotation gauche-droite
Avl *DoubleRG(Avl *a) {
    a->fd = rotationD(a->fd);
    return rotationG(a);
}

// Fonction pour effectuer une double rotation droite-gauche
Avl *DoubleRD(Avl *a) {
    a->fg = rotationG(a->fg);
    return rotationD(a);
}

// Fonction pour rééquilibrer l'arbre AVL
Avl *equilibreAVL(Avl *a) {
    if (a->equilibre >= 2) {
        if (a->fd->equilibre >= 0) {
            return rotationG(a);
        } else {
            return DoubleRG(a);
        }
    } else if (a->equilibre <= -2) {
        if (a->fg->equilibre <= 0) {
            return rotationD(a);
        } else {
            return DoubleRD(a);
        }
    }
    return a;
}

// Fonction pour insérer un nœud dans l'arbre AVL
Avl *insertionAVL(Avl *a, int id, float min, float max, float moy, float diff, int *h) {
    if (a == NULL) {
        *h = 1;
        return creerAvl(id, min, max, moy, diff);
    } else if (diff < a->diff) {
        a->fg = insertionAVL(a->fg, id, min, max, moy, diff, h);
        *h = -*h;
    } else if (diff > a->diff) {
        a->fd = insertionAVL(a->fd, id, min, max, moy, diff, h);
    } else {
        *h = 0;
        return a;
    }
    if (*h != 0) {
        a->equilibre = a->equilibre + *h;
        a = equilibreAVL(a);
        if (a->equilibre == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return a;
}

// Fonction pour lire les données depuis un fichier CSV et les insérer dans l'arbre AVL
void lireDonneesDepuisFichier(Avl **a, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier %s\n", nomFichier);
        exit(EXIT_FAILURE);
    }

    char ligne[4096];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        int id;
        float min, max, moy, diff;

        if (sscanf(ligne, "%d,%f,%f,%f,%f", &id, &min, &max, &moy, &diff) == 5) {
            int h = 0;
            *a = insertionAVL(*a, id, min, max, moy, diff, &h);
        } else {
            fprintf(stderr, "Erreur : Format de ligne invalide dans le fichier\n");
        }
    }

    fclose(fichier);
}

// Fonction pour trier les données dans l'arbre AVL
void trierAVL(Avl *a, DonneeTriee *donnees, int *index) {
    if (a == NULL) {
        return;
    }

    trierAVL(a->fg, donnees, index);

    // Stocker les données du nœud dans le tableau
    donnees[*index].id = a->id;
    donnees[*index].min = a->distance_min;
    donnees[*index].max = a->distance_max;
    donnees[*index].moy = a->distance_moy;
    donnees[*index].diff = a->diff;
    (*index)++;

    trierAVL(a->fd, donnees, index);
}

// Comparateur pour le tri en fonction de la différence distance_maxi - distance_mini
int comparerDonnees(const void *a, const void *b) {
    float diffA = ((DonneeTriee *)a)->max - ((DonneeTriee *)a)->min;
    float diffB = ((DonneeTriee *)b)->max - ((DonneeTriee *)b)->min;

    if (diffA > diffB) {
        return -1;
    } else if (diffA < diffB) {
        return 1;
    } else {
        return 0;
    }
}

// Fonction pour reconstruire l'arbre AVL à partir des données triées
Avl *reconstruireAVL(DonneeTriee *donnees, int debut, int fin) {
    if (debut > fin) {
        return NULL;
    }

    int milieu = (debut + fin) / 2;
    Avl *nouveau = creerAvl(donnees[milieu].id, donnees[milieu].min, donnees[milieu].max, donnees[milieu].moy, donnees[milieu].diff);

    nouveau->fg = reconstruireAVL(donnees, debut, milieu - 1);
    nouveau->fd = reconstruireAVL(donnees, milieu + 1, fin);

    return nouveau;
}

// Fonction pour trier les données dans l'arbre AVL
void trierDonnees(Avl **a) {
    // Compter le nombre de nœuds dans l'arbre
    int taille = compterNoeuds(*a);

    // Allouer un tableau pour stocker les données triées
    DonneeTriee *donneesTriees = malloc(taille * sizeof(DonneeTriee));

    // Indice pour suivre la position actuelle dans le tableau
    int index = 0;

    // Remplir le tableau avec les données de l'arbre AVL
    trierAVL(*a, donneesTriees, &index);

    // Trier le tableau en fonction de la différence distance_maxi - distance_mini
    qsort(donneesTriees, taille, sizeof(DonneeTriee), comparerDonnees);

    // Reconstruire l'arbre AVL à partir des données triées
    *a = reconstruireAVL(donneesTriees, 0, taille - 1);

    // Libérer la mémoire allouée pour le tableau
    free(donneesTriees);
}

// Fonction pour générer le graphique min-max-moyenne
void genererGraphique(Avl *a) {
    // Implémentez la génération du graphique ici
}

// Fonction principale
int main(void) {
    Avl *a = NULL;
    
    lireDonneesDepuisFichier(&a, "data.csv");
    
    trierDonnees(&a);
    
    genererGraphique(a);
    
    // Libérer la mémoire de l'arbre AVL si nécessaire
    
    return 0;
}
