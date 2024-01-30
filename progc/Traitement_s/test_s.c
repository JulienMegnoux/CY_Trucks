#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un nœud dans l'AVL avec la structure Arbre
typedef struct arbre {
    int idtrajet;
    float distance;
    float min;
    float max;
    float moy;
    float differenceMinMax;
    int nb;
    struct arbre* fg;
    struct arbre* fd;
    int equilibre;
} Arbre;

// Fonction pour obtenir la hauteur d'un nœud
int maxHeight(Arbre* node) {
    if (node == NULL) return 0;
    return node->equilibre;
}

// Fonction pour obtenir le maximum de deux entiers
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// Créer un nouveau nœud avec une valeur donnée de type Arbre
Arbre* newNode(int idtrajet, float distance, float min, float max, float moy, float diffMinMax, int nb) {
    Arbre* node = (Arbre*)malloc(sizeof(Arbre));
    node->idtrajet = idtrajet;
    node->distance = distance;
    node->min = min;
    node->max = max;
    node->moy = moy;
    node->differenceMinMax = diffMinMax;
    node->nb = nb;
    node->fg = NULL;
    node->fd = NULL;
    node->equilibre = 1;
    return node;
}

// Rotation à droite autour du nœud y
Arbre* rightRotate(Arbre* y) {
    Arbre* x = y->fg;
    Arbre* T2 = x->fd;

    // Effectuer la rotation
    x->fd = y;
    y->fg = T2;

    // Mettre à jour les hauteurs
    y->equilibre = maximum(maxHeight(y->fg), maxHeight(y->fd)) + 1;
    x->equilibre = maximum(maxHeight(x->fg), maxHeight(x->fd)) + 1;

    // Retourner le nouveau nœud racine
    return x;
}

// Rotation à gauche autour du nœud x
Arbre* leftRotate(Arbre* x) {
    Arbre* y = x->fd;
    Arbre* T2 = y->fg;

    // Effectuer la rotation
    y->fg = x;
    x->fd = T2;

    // Mettre à jour les hauteurs
    x->equilibre = maximum(maxHeight(x->fg), maxHeight(x->fd)) + 1;
    y->equilibre = maximum(maxHeight(y->fg), maxHeight(y->fd)) + 1;

    // Retourner le nouveau nœud racine
    return y;
}

// Obtenir le facteur d'équilibre d'un nœud
int getBalance(Arbre* node) {
    if (node == NULL) return 0;
    return maxHeight(node->fg) - maxHeight(node->fd);
}

// Insérer un nœud dans l'AVL
Arbre* insert(Arbre* node, int idtrajet, float distance, float min, float max, float moy, float diffMinMax, int nb) {
    // Effectuer l'insertion normale d'un BST
    if (node == NULL) return newNode(idtrajet, distance, min, max, moy, diffMinMax, nb);

    if (idtrajet > node->idtrajet)
        node->fd = insert(node->fd, idtrajet, distance, min, max, moy, diffMinMax, nb);
    else if (idtrajet < node->idtrajet)
        node->fg = insert(node->fg, idtrajet, distance, min, max, moy, diffMinMax, nb);
    else // Les valeurs égales ne sont pas autorisées dans un AVL
        return node;

    // Mettre à jour la hauteur du nœud actuel
    node->equilibre = 1 + maximum(maxHeight(node->fg), maxHeight(node->fd));

    // Obtenir le facteur d'équilibre du nœud pour vérifier l'équilibre
    int balance = getBalance(node);

    // Cas de déséquilibre, rotation nécessaire
    // Rotation à droite-droite
    if (balance > 1 && idtrajet < node->fg->idtrajet)
        return rightRotate(node);

    // Rotation à gauche-gauche
    if (balance < -1 && idtrajet > node->fd->idtrajet)
        return leftRotate(node);

    // Rotation à gauche-droite
    if (balance > 1 && idtrajet > node->fg->idtrajet) {
        node->fg = leftRotate(node->fg);
        return rightRotate(node);
    }

    // Rotation à droite-gauche
    if (balance < -1 && idtrajet < node->fd->idtrajet) {
        node->fd = rightRotate(node->fd);
        return leftRotate(node);
    }

    // Le nœud est équilibré
    return node;
}

// Afficher les valeurs d'un AVL en ordre décroissant
// Afficher les valeurs d'un AVL en ordre décroissant
void printAVL(Arbre* root) {
    if (root != NULL) {
        // Afficher les valeurs en ordre décroissant
        printf("Visiting node with idtrajet: %d\n", root->idtrajet);
        printAVL(root->fd);
        printAVL(root->fg);
    }
}


// Lire les valeurs à partir d'un fichier et insérer dans l'AVL
void readFromFileAndInsert(Arbre** root, const char* fileName) {
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", fileName);
        exit(EXIT_FAILURE);
    }

    int idtrajet, nb;
    float distance, min, max, moy, diffMinMax;

    while (fscanf(file, "%d %f %f %f %f %f %d", &idtrajet, &distance, &min, &max, &moy, &diffMinMax, &nb) == 7) {
        *root = insert(*root, idtrajet, distance, min, max, moy, diffMinMax, nb);
    }

    fclose(file);
}

// Programme principal
int main() {
    Arbre* root = NULL;

    // Lire les données du fichier et les insérer dans l'AVL
    readFromFileAndInsert(&root, "resultat.txt");

    // Afficher les valeurs triées par ordre décroissant
    printf("Valeurs triées par ordre décroissant : \n");
    printAVL(root);

    return 0;
}

