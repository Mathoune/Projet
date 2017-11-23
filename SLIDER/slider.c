#include <stdio.h>
#include <stdlib.h>

#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"

int main (int argc, char*argv[]) {
	printf("Debut slider\n");

	SLIDER S;
	S = lire_fichier(argv[1]);
	printf ("S.H= %d S.L= %d \n", S.H, S.L);
	printf ("S.x= %d S.y= %d \n", S.x, S.y);
	printf ("S.px= %d S.py= %d \n", S.px, S.py);
	initialiser_affichage(S);
	
	afficher_slider(S);


	printf("Fin slider\n");
	finir_affichage(S);
	wait_escape();
	exit(0);
}
