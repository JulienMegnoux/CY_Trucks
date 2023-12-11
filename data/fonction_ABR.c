#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include <errno.h>

typedef struct arbre{
	int valeur;
	struct arbre* fg;
	struct arbre* fd;
}Arbre;


typedef struct chainon{
	Arbre* pa;
	struct chainon* pnext;
}Chainon;

typedef struct file{
	Chainon* tete;
	Chainon* queue;
}File;


Chainon* creationChainon(Arbre* pArbre){
    // Allocate a node structure

    if(pArbre==NULL){

    	exit(57);
    }
    Chainon* pC = malloc( sizeof(Chainon) );
    // check if addres is not NULL
    if(pC == NULL){
        printf("NODE malloc failed !\n");
        exit(1);
    }
    // init structure
    pC->pa   = pArbre;
    pC->pnext = NULL;
    // return address
    return pC; 
}

File* creationFile(){
	File* pFile = malloc(sizeof(File));
	if(pFile == NULL){
		exit(12);
	}
	pFile->tete = NULL;
	pFile->queue = NULL;
	return pFile;
}



Arbre* creerArbre(int valeur){ 

	Arbre* pnoeud=NULL;
	pnoeud=malloc(sizeof(Arbre));
	pnoeud->valeur=valeur;
	pnoeud->fg=NULL;
	pnoeud->fd = NULL;
	return pnoeud;
}
Arbre* pArbre=NULL;

void enfiler(File* pfile, Arbre* pArbre){

	Chainon* pnew=NULL;
	if(pfile==NULL || pArbre==NULL){
		exit(14);
	}
	pnew=creationChainon(pArbre);
	if(pnew == NULL){
		exit(13);
	}
	if(pfile->queue==NULL){
		pfile->tete=pnew;
		pfile->queue=pnew;
	}
	else{
		pfile->queue->pnext = pnew;
		pfile->queue=pnew;
	}
}

Arbre* defile(File* pfile){
	Arbre* pArbre = NULL;
	if(pfile==NULL){
		exit(14);
	}
	if(pfile->tete==NULL){

		exit(47);
	}
	pArbre = pfile->tete->pa;
	pfile->tete = pfile->tete->pnext;
	if(pfile->tete == NULL){
		pfile->queue = NULL;
	}
	return pArbre;
}



int estVide(Arbre* pArbre){ 
	if(pArbre==NULL){
		return 1;
	}
	else{
		return 0;
	}
}





int estFeuille(Arbre* pArbre){
	if(pArbre==NULL){
		exit(26);
	}
	if(pArbre->fd==NULL && pArbre->fg==NULL){
		return 1;
	}
	else{
		return 0;
	}
}




int element(Arbre* pArbre){ 
if (pArbre==NULL){
		exit(1);
	}
	return pArbre->valeur;

}


int existeFilsGauche(Arbre* pArbre){ 
	if(pArbre->fg==NULL){
		return 0;
	}
	else{
		return 1;
	}
}



int existeFilsDroit(Arbre* pArbre){
	if(pArbre->fd==NULL){
		return 0;
	}
	else{
		return 1;
	}
}




int ajouterfilsGauche(Arbre* pArbre,int valeur){ 
	if (pArbre==NULL){
		pArbre=creerArbre(valeur);
		pArbre->valeur=valeur;
		return 1;
	}
	else if(existeFilsGauche(pArbre)==0){
		pArbre->fg=creerArbre(valeur);
		return 1;
	}
	else{
		return 0;
	}
}

int ajouterfilsDroit(Arbre* pArbre,int valeur){ 
	if (pArbre==NULL){
		pArbre=creerArbre(valeur);
		pArbre->valeur=valeur;
		return 1;
	}
	else if(existeFilsDroit(pArbre)==0){
		pArbre->fd=creerArbre(valeur);
		return 1;
	}
	else{
		return 0;
	}
}


void traiter(Arbre* pArbre){ 
	if(pArbre==NULL){
		exit(15);
	}
	printf("%d ",pArbre->valeur);
}


void parcoursPrefixe(Arbre* pArbre){

	if(pArbre!=NULL){
		traiter(pArbre);
		parcoursPrefixe(pArbre->fg);
		parcoursPrefixe(pArbre->fd);
	}
}



void parcoursInfixe(Arbre* pArbre){
	if(pArbre!=NULL){
		parcoursInfixe(pArbre->fg);
		traiter(pArbre);
		parcoursInfixe(pArbre->fd);
	}
}


void parcoursLargeur(Arbre* pArbre){
	Arbre* pnoeud=NULL;
	File* pfile=NULL;
	if(pArbre!=NULL){
		pfile=creationFile();
		if(pfile==NULL){
			exit(67);
		}
		enfiler(pfile,pArbre);
		while(pfile->tete!=NULL){
			pnoeud=defile(pfile);
			traiter(pnoeud);
			if(existeFilsGauche(pnoeud)){
				enfiler(pfile,(pnoeud->fg));
			}
			if(existeFilsDroit(pnoeud)){
				enfiler(pfile,(pnoeud->fd));
			}
		}
	}
}

void modifierelt(Arbre* pArbre,int elmt){
	if(pArbre==NULL){
		exit(153);
	}
	else{
		pArbre->valeur=elmt;
	}
}


void suppfilsdroit(Arbre* pArbre);

Arbre* suppfilsgauche(Arbre* pArbre){
	if(pArbre==NULL){
		exit(90);
	}
	else if(existeFilsGauche(pArbre)==1){
		if(existeFilsDroit(pArbre->fd)){
			suppfilsdroit(pArbre->fd);
		}
		if(existeFilsGauche(pArbre)==1){
			suppfilsgauche(pArbre->fd);
		}
	}
}

void suppfilsdroit(Arbre* pArbre){
	if(pArbre==NULL){
		exit(180);
	}
	else if(existeFilsDroit(pArbre)==1){
		if(existeFilsGauche(pArbre->fd)){
			suppfilsgauche(pArbre->fd);
		}
		if(existeFilsDroit(pArbre)==1){
			suppfilsdroit(pArbre->fd);
		}
	}
}

// TD ABR

bool recherche(Arbre* pArbre,int elmt){
	if(pArbre==NULL){
		return false;
	}
	else if(pArbre->valeur==elmt){
		return true;
	}
	else if( elmt<pArbre->valeur){
		return recherche(pArbre->fg,elmt);
	}
	else{
		return recherche(pArbre->fd,elmt);
	}
}

Arbre* insertionABR(Arbre* pArbre,int elmt){
	if(pArbre==NULL){
		return creerArbre(elmt);
	}
	else if(elmt<pArbre->valeur){
		pArbre->fg=insertionABR(pArbre->fg,elmt);
	}
	else if(elmt> pArbre->valeur){
		pArbre->fd=insertionABR(pArbre->fd,elmt);
	}
	return pArbre;
} 


Arbre* suppMax(Arbre* pArbre,int* pvaleur){
	Arbre* tmp;
	if(existeFilsDroit(pArbre)==1){
		pArbre->fd=suppMax(pArbre->fd,pvaleur);
	}
	else{
		*pvaleur=pArbre->valeur;
		tmp=pArbre;
		pArbre=pArbre->fg;
		free(tmp);
	}

	return pArbre;
}

Arbre* surppression(Arbre* pArbre,int elmt){ 
	Arbre* tmp;
	if(pArbre==NULL){
		return pArbre;
	}
	else if(elmt>pArbre->valeur){
		pArbre->fd=surppression(pArbre->fd,elmt);
	}
	else if(elmt<pArbre->valeur){
		pArbre->fg=surppression(pArbre->fg,elmt);
	}
	else if(existeFilsGauche(pArbre)==0){
		tmp=pArbre;
		pArbre=pArbre->fd;
		free(tmp);
	}
	else{
		pArbre->fg=suppMax(pArbre->fg,&(pArbre->valeur));
	}
	return pArbre;
}



int main(){

	printf("%s","TG");
	return 0;
}

