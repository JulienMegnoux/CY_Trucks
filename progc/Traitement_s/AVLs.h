#ifndef _AVL_
#define _AVL_

// declaration de la structure
typedef struct arbre{
  int idtrajet;   
  float distance;
  float min;
  float max;
  float moy;
  int nb;
  struct arbre *fg;
  struct arbre *fd;
  int equilibre;
}Arbre;


typedef Arbre *pArbre;


// fonction qu'on utilise
int min(int a, int b);
int min3(int a, int b, int c);
int max(int a, int b);
int max3(int a, int b, int c);
void afficherArbre(pArbre a);
void afficherArbre2(pArbre a);

// rotation
pArbre rotationGauche(pArbre a);
pArbre rotationDroite(pArbre a);
pArbre doubleRotationGauche(pArbre a);
pArbre doubleRotationDroite(pArbre a);
pArbre equilibrer(pArbre a);



// creer un arbre et insertion par rapport a Idtrajet
pArbre creerArbre(int idtrajet, float dist);
pArbre insertionT(pArbre a, int idtrajet, float dist, int *h);



// creer un arbre et insertion par rapport a distance
pArbre creerArbreD(int idtrajet, float dist, float max, float min, int nb);
pArbre insertionD(pArbre b, int idtrajet, float dist, float max, float min, int nb, int *h);
pArbre CopieEtInsertionD(pArbre a, pArbre b);


#endif
