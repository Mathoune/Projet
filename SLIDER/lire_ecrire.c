#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

SLIDER lire_taille(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d %d ",&S.L, &S.H);
	return S;
}
SLIDER lire_position(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d %d ",&S.x, &S.y);
	return S;
}
SLIDER lire_sortie(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d %d ",&S.px, &S.py);
	printf ("S.px= %d S.py= %d \n", S.px, S.py);
	return S;
}
SLIDER lire_murs(FILE* fichier, SLIDER S)
{
	fscanf(fichier,"%d ", &S.N);
	S.murx=malloc((S.N)*sizeof(int));
	S.mury=malloc((S.N)*sizeof(int));
	S.murz=malloc((S.N)*sizeof(int));
	printf ("N= %d\n", S.N);
	int n=0;
	while(n!=S.N)
	{
		fscanf(fichier,"%d %d %d", &S.murx[n], &S.mury[n], &S.murz[n]);
		printf ("murx= %d mury= %d murz= %d \n", S.murx[n], S.mury[n], S.murz[n]);
		n++;
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
