#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

SLIDER lire_taille(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d %d ",&S.L, &S.H);
	//printf ("S.H= %d S.L= %d \n", S.H, S.L);
	return S;
}
SLIDER lire_position(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d %d ",&S.x, &S.y);
	//printf ("S.x= %d S.y= %d \n", S.x, S.y);
	return S;
}
SLIDER lire_sortie(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d %d ",&S.px, &S.py);
	//printf ("S.px= %d S.py= %d \n", S.px, S.py);
	return S;
}
SLIDER lire_murs(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d ", &S.N);
	S.murs_x=malloc((S.N)*sizeof(int));
	S.murs_y=malloc((S.N)*sizeof(int));
	int n=S.N;
	while(n)
	{
		fscanf(fichier,"%d %d", S.murs_x, S.murs_y);
		n--;
	}
	
	return S;
}



SLIDER lire_fichier(char *nom) {

	FILE* fichier= NULL;
	fichier=fopen(nom,"r");
	printf("nom = %s\n",nom);
	SLIDER S;
	S = lire_taille(fichier, S);
	S = lire_position(fichier, S);
	S = lire_sortie(fichier, S);
	S = lire_murs(fichier, S);
	fclose(fichier);
	return S;
}


void ecrire_fichier(SLIDER S, char*nom) {
}
