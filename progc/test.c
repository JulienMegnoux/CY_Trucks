#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VILLE_NAME_SIZE 35
#define MAX_CITIES 10

// Structure pour stocker les informations sur une ville
typedef struct CityAppearance {
    char name[VILLE_NAME_SIZE];
    int totalVisits;
    struct CityAppearance *left;
    struct CityAppearance *right;
    int height;
} CityAppearance;

// Fonction utilitaire pour retourner le maximum entre deux entiers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Fonction pour calculer la hauteur d'un nœud dans l'arbre
int height(CityAppearance *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Crée un nouveau nœud pour une ville avec son nom et initialise les données
CityAppearance *newCity(char *name) {
    CityAppearance *city = (CityAppearance *)malloc(sizeof(CityAppearance));
    strcpy(city->name, name);
    city->totalVisits = 1;
    city->left = NULL;
    city->right = NULL;
    city->height = 1;
    return city;
}

// Fonctions pour effectuer les rotations dans l'arbre AVL
CityAppearance *rotateRight(CityAppearance *y) {
    CityAppearance *x = y->left;
    CityAppearance *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

CityAppearance *rotateLeft(CityAppearance *x) {
    CityAppearance *y = x->right;
    CityAppearance *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Fonction pour obtenir l'équilibre d'un nœud dans l'arbre
int calculateBalance(CityAppearance *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Fonction pour insérer une ville dans l'arbre
CityAppearance *insertCity(CityAppearance *node, char *name) {
    if (node == NULL)
        return newCity(name);

    if (strcmp(name, node->name) < 0)
        node->left = insertCity(node->left, name);
    else if (strcmp(name, node->name) > 0)
        node->right = insertCity(node->right, name);
    else {
        (node->totalVisits)++;
        return node;
    }

    // Mettre à jour la hauteur du nœud
    node->height = 1 + max(height(node->left), height(node->right));
    // Vérifier l'équilibre du nœud et effectuer des rotations si nécessaire
    int balance = calculateBalance(node);

    if (balance > 1 && strcmp(name, node->left->name) < 0)
        return rotateRight(node);

    if (balance < -1 && strcmp(name, node->right->name) > 0)
        return rotateLeft(node);

    if (balance > 1 && strcmp(name, node->left->name) > 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && strcmp(name, node->right->name) < 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Parcours l'arbre pour récupérer les 10 villes avec le plus de visites
void traversePrefix(CityAppearance *root, CityAppearance *topCities[], int *numCities) {
    if (root != NULL) {
        traversePrefix(root->left, topCities, numCities);

        if (*numCities < MAX_CITIES) {
            topCities[(*numCities)++] = root;
        } else {
            int minVisits = topCities[0]->totalVisits;
            int minIndex = 0;

            for (int i = 1; i < MAX_CITIES; i++) {
                if (topCities[i]->totalVisits < minVisits) {
                    minVisits = topCities[i]->totalVisits;
                    minIndex = i;
                }
            }

            if (root->totalVisits > minVisits) {
                topCities[minIndex] = root;
            }
        }

        traversePrefix(root->right, topCities, numCities);
    }
}

int compareVisits(const void *a, const void *b) {
    const CityAppearance *cityA = *(const CityAppearance **)a;
    const CityAppearance *cityB = *(const CityAppearance **)b;
    return (cityB->totalVisits - cityA->totalVisits);
}

int main() {
    FILE *file;
    char line[1024];

    CityAppearance *root = NULL;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        char *token;
        char *columns[5];

        int column = 0;
        token = strtok(line, ";");
        while (token != NULL && column < 5) {
            columns[column++] = token;
            token = strtok(NULL, ";");
        }

        if (column >= 4) {
            char *city = columns[3];

            if (strlen(city) < VILLE_NAME_SIZE) {
                root = insertCity(root, city);
            }
        }

        if (column >= 2 && atoi(columns[1]) == 1 && column >= 3) {
            char *departureCity = columns[2];

            if (strlen(departureCity) < VILLE_NAME_SIZE) {
                root = insertCity(root, departureCity);
            }
        }
    }

    fclose(file);

    CityAppearance *topCities[MAX_CITIES];
    int numTopCities = 0;

    traversePrefix(root, topCities, &numTopCities);

    qsort(topCities, numTopCities, sizeof(CityAppearance *), compareVisits);

    printf("Les 10 villes avec le plus de visites :\n");
    for (int i = 0; i < numTopCities && i < MAX_CITIES; i++) {
        printf("%s : Total Visites - %d\n", topCities[i]->name, topCities[i]->totalVisits);
    }

    return EXIT_SUCCESS;
}

