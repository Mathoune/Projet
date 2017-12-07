#include <stdlib.h>
#include <stdio.h>
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
void ecrire_position_sortie()
{
	
}
void ecrire_position_slider()
{
	
}

void ecrire_mur() //demande nombre de murs
{
	
}

void editeur(SLIDER S, int L,int H,char* nom)
{
	FILE * f=NULL;
	f=fopen(nom,"w+");
	ecrire_taille_init(f,L,H,S);
}
