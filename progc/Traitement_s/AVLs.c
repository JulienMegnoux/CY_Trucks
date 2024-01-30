#include "AVLs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// création arbre pour IDtrajet
pArbre creerArbre(int idtrajet, float dist)
{
    pArbre n = malloc(sizeof(Arbre));
    if (n == NULL){
      exit(56);
    }
    n->distance = dist;
    n->idtrajet = idtrajet;
    n->min = dist;
    n->max = dist;
    n->moy = 0; // on calcul la moyenne lors de la création du 2e arbre
    n->nb = 1;
    n->fg = NULL;
    n->fd = NULL;
    n ->differenceMinMax = 0;
    n->equilibre = 0;
    return n;
}


int min(int a, int b)
{
    return (a < b) ? a : b;
}

int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

pArbre rotationGauche(pArbre a)
{
    pArbre pivot;
    int eq_a;
    int eq_p;
    pivot = a->fd;
    a->fd = pivot->fg;
    pivot->fg = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - max(eq_p, 0) - 1;
    pivot->equilibre = min3(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);
    a = pivot;
    return a;
}

pArbre rotationDroite(pArbre a)
{
    pArbre pivot;
    int eq_a;
    int eq_p;
    pivot = a->fg;
    a->fg = pivot->fd;
    pivot->fd = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - min(eq_p, 0) + 1;
    pivot->equilibre = max3(eq_a + 2, eq_a + eq_p + 2, eq_p + 1);
    a = pivot;
    return a;
}

pArbre doubleRotationGauche(pArbre a)
{
    a->fd = rotationDroite(a->fd);
    return rotationGauche(a);
}

pArbre doubleRotationDroite(pArbre a)
{
    a->fg = rotationGauche(a->fg);
    return rotationDroite(a);
}


pArbre equilibrer(pArbre a)
{
    if (a->equilibre >= 2)
    { // sous-arbre droit plus profond
        if (a->fd->equilibre >= 0)
        {
            return rotationGauche(a);
        }
        else
        {
            return doubleRotationGauche(a);
        }
    }
    else if (a->equilibre <= -2)
    { // sous-arbre gauche plus profond
        if (a->fg->equilibre <= 0)
        {
            return rotationDroite(a);
        }
        else
        {
            return doubleRotationDroite(a);
        }
    }
    return a;
}


// insertion par rapport a idTrajet
pArbre insertionT(pArbre a, int idtrajet, float dist, int *h)
{
    if (a == NULL)
    {
        *h = 1;
        return creerArbre(idtrajet, dist);
    }
    else if (idtrajet < a->idtrajet)
    {
        a->fg = insertionT(a->fg, idtrajet, dist, h);
        *h = -(*h);
    }
    else if (idtrajet > a->idtrajet)
    {
        a->fd = insertionT(a->fd, idtrajet, dist, h);
    }
    else
    {
        if (a->max < dist){
            a->max = dist;
        }
        if (a->min > dist){
            a->min = dist;
        }
        a->distance = a->distance + dist;
        a->nb = a->nb + 1;
        *h = 0;
        return a;
    }
    if (*h != 0)
    {
        a->equilibre = a->equilibre + *h;
        a = equilibrer(a);
        if (a->equilibre == 0)
        {
            *h = 0;
        }
        else
        {
            *h = 1;
        }
    }
    return a;
}

// création arbre pour Distance
pArbre creerArbreD(int idtrajet, float dist, float max, float min, int nb)
{
    pArbre n = malloc(sizeof(Arbre));
    if (n == NULL){
      exit(57);
    }
    n->distance = dist;
    n->idtrajet = idtrajet;
    n->min = min;
    n->max = max;
    n->moy = max-min;  // nb ne peut pas etre = 0 car dans le premier arbre lors de la création d'une racine on initie nb = 1.
    n->nb = nb;
    n->fg = NULL;
    n->fd = NULL;
    n->equilibre = 0;
    return n;
}


// insertion par rapport a distance
pArbre insertionD(pArbre b, int idtrajet, float dist, float max, float min, int nb, int *h)
{
    if (b == NULL)
    {
        *h = 1;
        return creerArbreD(idtrajet, dist, max, min, nb);
    }
    else if (dist < b->distance)
    {
        b->fg = insertionD(b->fg, idtrajet, dist, max, min, nb, h);
        *h = -(*h);
    }
    else if (dist > b->distance)
    {
        b->fd = insertionD(b->fd, idtrajet, dist, max, min, nb, h);
    }
    else
    {
        *h = 0;
        return b;
    }
    if (*h != 0)
    {
        b->equilibre = b->equilibre + *h;
        b = equilibrer(b);
        if (b->equilibre == 0)
        {
            *h = 0;
        }
        else
        {
            *h = 1;
        }
    }
    return b;
}

pArbre CopieEtInsertionD(pArbre a, pArbre b){
  if (a != NULL){
    CopieEtInsertionD(a->fg, b);
    int h = 0;
    b = insertionD(b, a->idtrajet, a->distance, a->max, a->min, a->nb, &h);
    CopieEtInsertionD(a->fd, b);
  }
  return b;
}



void afficherArbre(pArbre a){
    if (a != NULL)
    {
    	for(int i=0;i<50;i++){
        afficherArbre(a->fg);
        printf("(trajetID: %d, distance: %.2f, équilibre: %d) ", a->idtrajet, a->distance, a->equilibre);
        afficherArbre(a->fd);
    }
}
}

void afficherArbre2(pArbre a){
  if (a != NULL){
  		
    afficherArbre2(a->fg);
    //printf("(trajetID: %d, distance: %.2f, max: %.2f, min: %.2f, moy: %.2f, nb: %d, équilibre: %d\n)", a->idtrajet, a->distance, a->max, a->min, a->moy, a->nb, a->equilibre);
    printf("moy: %.2f\n",a->moy);
    afficherArbre2(a->fd);
    }
  }		




