#include <stdlib.h>
#include <stdio.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"


SLIDER ecrire_taille_init(FILE * f,int L,int H,SLIDER S)
{
	fprintf(f,"%d %d \n",L,H);
	S.L=L; S.H=H;
	initialiser_affichage(S);
	afficher_grille(S);
	return S;
}
SLIDER ecrire_position_sortie(FILE * f,SLIDER S)
{
	int a,fl; char c; POINT p;
	a=0;
	while(a!= EST_CLIC){
	a = wait_key_arrow_clic (&c, &fl, &p);
    SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
	}
	S.sx=p.x/Taille_Case;
	S.sy=p.y/Taille_Case;
	afficher_sortie(S);
	fprintf(f,"%d %d \n",S.sx,S.sy);
	
	return S;
}
SLIDER ecrire_position_slider(FILE * f,SLIDER S)
{
	int a,fl; char c; POINT p;
	a=0;
	while(a!= EST_CLIC){
	a = wait_key_arrow_clic (&c, &fl, &p);
    SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
	}
	S.x=p.x/Taille_Case;
	S.y=p.y/Taille_Case;
	S.ps.x=((S.x)*Taille_Case)+(Taille_Case/2); S.ps.y=((S.y)*Taille_Case)+(Taille_Case/2);
	afficher_le_slider(S);
	fprintf(f,"%d %d \n",S.x,S.y);
	return S;
}

SLIDER ecrire_nb_murs(FILE * f,SLIDER S) //demande nombre de murs
{
	int a,fl; char c; POINT p;
	a=0; c='a';
	
	while(a!= EST_TOUCHE){
	a = wait_key_arrow_clic (&c, &fl, &p);
    SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
    printf("%d",c);
	}
	S.N=c;
	return S;
}
SLIDER place_mur(POINT p, SLIDER S)
{
	int x,y,z;
	return S;
}
SLIDER ecrire_murs(FILE * f,SLIDER S)
{
	int a,fl,n; char c; POINT p;
	a=n=0;
	while(a!= EST_CLIC && n!=S.N){
	a = wait_key_arrow_clic (&c, &fl, &p);
    S=place_mur(p,S);
    n++;
	}
}

void editeur(SLIDER S, int L,int H,char* nom)
{
	FILE * f=NULL;
	f=fopen(nom,"w+");
	ecrire_taille_init(f,L,H,S);
	ecrire_position_slider(f,S);
	ecrire_position_sortie(f,S);
	printf("Donnez le nombre de murs souhaité \n");
	ecrire_nb_murs(f,S);
	fclose(f);
}
