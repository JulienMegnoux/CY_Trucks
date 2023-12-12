typedef struct arbre{
	int valeur;
	struct arbre* fg;
	struct arbre* fd;
	int equilibre;
}Arbre;


Arbre* creerArbre(int valeur){ 

	Arbre* pnoeud=NULL;
	pnoeud=malloc(sizeof(Arbre));
	pnoeud->valeur=valeur;
	pnoeud->fg=NULL;
	pnoeud->fd = NULL;
	return pnoeud;
}
Arbre* pArbre=NULL;



Arbre* insertionAVL(Arbre* pArbre, int elt, int h*){

	if(pArbre==NULL){

		*h=1
		return creerArbre(elt);
	}

	else if(elt< pArbre-> valeur){
		pArbre->fg = insertionAVL(pArbre(fg),elt,h);
		*h=-*h;
	}
	else if (elt> pArbre-> valeur){
		pArbre->fd=insertionAVL(pArbre->fd,elt,h);
	}
	else{
		*h=0;
	return pArbre;
		 
	}

	if(*h!=0){

		pArbre(equilibre)=pArbre(equilibre) + *h;
		if(pArbre-> equilibre == 0){
			*h=0;
		}
		else{

			*h=1;
		}
	}
	return pArbre;
}


Arbre* suppressionAVL(Arbre* pArbre, int elt, Arbre* pelt){

	Arbre* tmp;

	if(pArbre==NULL){

		*h=1;
		return pArbre;
	}

	else if(elt>pArbre->valeur{

		pArbre->fd=suppressionAVL(pArbre->fd,elt);
	}

	else if(elt<pArbre->valeur){

		pArbre->fg =suppressionAVL(pArbre->fg,elt);
		*h=-*h
	}
	else if (existeFilsDroit(pArbre)){

		pArbre->fg=suppMinAVL(pArbre->fd,h, &pArbre->elt)
	}
	else{

		tmp=pArbre;
		pArbre=pArbre->fg;
		free(tmp);
		*h=-1
	}

	if(*h!=0){

		pArbre->equilibre=pArbre->equilibre+*h;
		if(pArbre->equilibre==0){

			*h=0
		}
		else{

			*h=1;
		}
	}
	return pArbre;


Arbre* suppMinAVL(Arbre* pArbre, int h*, Arbre* pelt){

	Arbre* tmp;
	if (pArbre->fg==NULL){

		*pelt=pArbre->valeur;
		
		tmp=pArbre;
		pArbre=pArbre->fd;
		free(tmp);
		*h=-1
		return pArbre;
	}
	else{

	pArbre->fg=suppMinAVL(pArbre->fg,h,pelt);
	*h=-*h;
}
	if(*h!=0){

		pArbre->equilibre=pArbre->equilibre+*h;
		if(pArbre->equilibre==0){

			*h=-1;
		}
		else{
			*h=0;
		}
	}
	return pArbre;
}


Arbre* equilibreAVL(Arbre* pArbre){

	if(pArbre->equilibre>= 2){

		if(pArbre->fd->equilibre>=0){
		return rotationG(pArbre);
	}
	else{

		return doublerotationG(pArbre);
	}
}

	else if(pArbre->equilibre<= -2){

		if(pArbre->fg->equilibre <= 0){

			return rotationD(pArbre);
		}
		else{

			return doublerotationD(pArbre);
		}
	}
	return pArbre;
}






Arbre* rotationG(Arbre* pArbre){

	Arbre* pivot;

	int eq_a;

	int eq_p;

	pivot=pArbre->fd;

	pArbre->fd=pivot->fg;

	pivot->fg=pArbre;

	eq_a=pArbre->equilibre;

	eq_p=pivot->equilibre;

	if (eq_p>0){
		pArbre->equilibre=eq_a - eq_p -1;
	}
	else{
		pArbre->equilibre=eq_a - 1;
	}
	pivot->equilibre=min(eq_a-2,eq_a+eq_p-2,eq_p-1);

	pArbre=pivot;

	return pArbre;
}

Arbre* doublerotationG(Arbre* pArbre){

	pArbre->fg=rotationD(pArbre->fd);
	return rotationG(pArbre);
}