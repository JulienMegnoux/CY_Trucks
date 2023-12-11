#include "header.h"

int tirage_affiche_piece(Piece tableau_pieces[7][4], int tirage, int* colonne){
	int nbr,i,j,k,l,orientation,largeur,end,test;
    test=0;
  
    
	if(tirage == 6){
		printf(" Voici le O :\n");
        for(k=0; k < 2; k++){
    	    for(l = 0; l < 2; l++){
        	    printf("%2s","@");
			}    
			printf("\n");
		}
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>10);
    
    }else if(tirage == 5){
        printf(" \nVoici le I :\n\n");
        for(k=0; k < 1; k++){
            for(l = 0; l < 4; l++){
    	        printf("%2s","@");
       		}
       	    printf("\n"); 
    	}
        printf(" \nVoici le I modif 1 :\n");
        for(k=0; k < 4; k++){
            for(l = 0; l < 1; l++){
    	        printf("%2s","@");
    		}
    	    printf("\n");
    	}
        do{
            printf("\nChoisissez l'orientation de la piece : \n");
            scanf("%d", &orientation);
            while(getc(stdin)!='\n');
        }while(orientation<0 && orientation>3);
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>11);

    }else if(tirage == 3){
  		printf(" \nVoici le S :\n");
  	    for(k = 0; k < 2; k++){
      	    for(l = 0; l < 3; l++){
                if(k==0 && l==0){
        	        printf("%2s","");
                }else if(k==1 && l==2){
                    printf("%2s","");
                }else{
          	        printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le S modif 1 :\n");
        for(k = 0; k < 3; k++){
    	    for(l = 0; l < 2; l++){
                if(k==0 && l==0){
        	        printf("%2s","");
                }else if(k==2 && l==1){
        	        printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        do{
            printf("\nChoisissez l'orientation de la piece : \n");
            scanf("%d", &orientation);
            while(getc(stdin)!='\n');
        }while(orientation<0 && orientation>3);
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>10);

    }else if(tirage == 4){
        printf(" \nVoici le Z :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
       	        if(k==1 && l==0){
       		        printf("%2s","");
                }else if(k==0 && l==2){
       		        printf("%2s","");
                }else{
       		        printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le Z modif 1 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
       		    if(k==0 && l==0){
       			    printf("%2s","");
                }else if(k==2 && l==1){
       			    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        do{
            printf("\nChoisissez l'orientation de la piece : \n");
            scanf("%d", &orientation);
            while(getc(stdin)!='\n');
        }while(orientation<0 && orientation>3);
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>10);

    }else if(tirage == 2){
        printf(" \nVoici le J :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
                if(k==1 && l==0){
                    printf("%2s","");
                }else if(k==1 && l==1){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le J modif 1 :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
                if(k==0 && l==1){
                    printf("%2s","");
                }else if(k==0 && l==2){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le J modif 2 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
                if(k==0 && l==0){
                    printf("%2s","");
                }else if(k==1 && l==0){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le J modif 3 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
                if(k==1 && l==1){
                    printf("%2s","");
                }else if(k==2 && l==1){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        do{
            printf("\nChoisissez l'orientation de la piece : \n");
            scanf("%d", &orientation);
            while(getc(stdin)!='\n');
        }while(orientation<0 && orientation>5);
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>10);

    }else if(tirage == 1){
        printf(" \nVoici le L :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
                if(k==1 && l==1){
                    printf("%2s","");
                }else if(k==1 && l==2){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le L modif 1 :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
                if(k==0 && l==0){
                    printf("%2s","");
                }else if(k==0 && l==1){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le L modif 2 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
                if(k==0 && l==1){
                    printf("%2s","");
                }else if(k==1 && l==1){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le L modif 3 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
                if(k==1 && l==0){
                    printf("%2s","");
                }else if(k==2 && l==0){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        do{
            printf("\nChoisissez l'orientation de la piece : \n");
            scanf("%d", &orientation);
            while(getc(stdin)!='\n');
        }while(orientation<0 && orientation>5);
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>10);
    
    }else if(tirage == 0){
        printf(" \nVoici le T :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
                if(k==1 && l==0){
                    printf("%2s","");
                }else if(k==1 && l==2){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le T modif 1 :\n");
        for(k = 0; k < 2; k++){
            for(l = 0; l < 3; l++){
                if(k==0 && l==0){
                    printf("%2s","");
                }else if(k==0 && l==2){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                } 
            }
            printf("\n");
        }
        printf(" \nVoici le T modif 2 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
                if(k==0 && l==0){
                    printf("%2s","");
                }else if(k==2 && l==0){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        printf(" \nVoici le T modif 3 :\n");
        for(k = 0; k < 3; k++){
            for(l = 0; l < 2; l++){
                if(k==0 && l==1){
                    printf("%2s","");
                }else if(k==2 && l==1){
                    printf("%2s","");
                }else{
                    printf("%2s","@");
                }
            }
            printf("\n");
        }
        do{
            printf("\nChoisissez l'orientation de la piece : \n");
            scanf("%d", &orientation);
            while(getc(stdin)!='\n');
        }while(orientation<0 && orientation>5);
        do{
            printf("\nChoisissez la colonne : \n");
            scanf("%d", colonne);
            while(getc(stdin)!='\n');
        }while(*colonne<0 && *colonne>10);
    }
    *colonne--;
    return orientation;
}

void init(char tab[10][10], char a){ // initialize all the array's cell to a typeface 'a'
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tab[i][j] = a;
        }
    }
}

void affiche_tableau(char tab_principal[10][10], int score){
    printf("\n Grille :\n\n");
    printf(" 0 1 2 3 4 5 6 7 8 9 \t\tscore : %d\n", score);
    for(int i=9; i>=0; i--){ // la case (0;0) est dans l'angle en bas à droite
        for(int j=0; j<10; j++){
            printf("|%c",tab_principal[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}




void move(char tab[10][10], int ligne){ // move the lines of the game table when one is completed
    for(int i=ligne; i<9; i++){
        for(int j=0; j<10; j++){
            tab[i][j] = tab[i+1][j];
        }
    }
    for(int i=0; i<10; i++){
        tab[9][i] = ' ';
    }
}





int addscore(int nbline){
    float score = 0;
    if(nbline == 1){
        score = 40;
    }else if(nbline == 2){
        score = 100;
    }else if(nbline == 3){
        score = 300;
    }else if(nbline == 4){
        score = 1200;
    }
    score += 10;
    return (int)score;
}





void compter_espaces(int piece, int orientation, Piece tableau_pieces[7][4], int tab[]){//compter les espaces sous chaque colone de la piece
    int nbr = 0;
    for(int i=0; i<tableau_pieces[piece][orientation].largeur; i++){
        for(int j=0; j<tableau_pieces[piece][orientation].hauteur; j++){
            if(*(tableau_pieces[piece][orientation].tab[j]+i) == ' '){
                nbr ++;
            }else{
                break;
            }
        }
        tab[i] = nbr;
        nbr = 0;
    }
}



    
    


void updatab(Piece tableau_pieces[7][4], char tab_principal[10][10], int colonne, int orientation, int piece, int *score, int *end){//actualiser le tableau
    int piece_size[4] = {0,0,0,0};
    compter_espaces(piece,orientation, tableau_pieces, piece_size);
    int places_libres[4] = {0,0,0,0};
    int tabsup[4];
    int hauteur = tableau_pieces[piece][orientation].hauteur;
    int height;
    int test = 0;
    int nbrligne = 0;
    int largeur = tableau_pieces[piece][orientation].largeur; 
    for(int i=0; i<largeur; i++){// compter où est la piece la + haute dans chaques colonnes
        for(int j=9; (j>=0) && (test == 0); j--){
            if(tab_principal[j][i+colonne]=='@'){
                places_libres[i]=j+1;
                test=1;
            }else if((j==0) && (test == 0)){
                places_libres[i] = 0;
            }
        }
        test = 0;
    }
    for(int i=0; i<4; i++){// compter a quelle hauteur chaque colonne de la piece pourrait descendre
        places_libres[i] = places_libres[i]-piece_size[i];
    }
    height = places_libres[0];
    for(int i=0; i<largeur-1; i++){// choisir la hauteur la plus haute
        if(places_libres[i]<places_libres[i+1]){
            height = places_libres[i+1];
        }
    }
    if(height<0){
        height = 0;
    }
    if(height+hauteur<=10){// si la piece ne sort pas du tableau
        for(int i=0; i<hauteur; i++){
            for(int j=0; j<largeur; j++){
                if(*(tableau_pieces[piece][orientation].tab[i]+j) == '@'){
                    tab_principal[i+height][j+colonne] = '@';
                }
            }
        }
        for(int i=0; i<10; i++){// compter le nombre de lignes completes
            int full=0;
            for(int j=0; j<10; j++){
                if(tab_principal[i][j]=='@'){
                    full++;
                    if(full==10){
                        tabsup[nbrligne]=i;
                        nbrligne++;
                    }
                }
            }
        }
        if(nbrligne>0){//si des lignes sont completes
            for(int i=0; i<nbrligne; i++){
                move(tab_principal, tabsup[i]-i);//decaler les lignes    
            }
        }
        *score += addscore(nbrligne);

    }else{
        *end = 1;
    }
}