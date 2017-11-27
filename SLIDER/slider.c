#include <stdio.h>
#include <stdlib.h>

#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "jeu.h"

int main (int argc, char* argv[]) {
	printf("Debut slider\n");
	JEU j; 
	SLIDER S;
	S = init_slider(argv[1]);
	
	afficher_slider (S);
	int i;
	j=ajout(j,S);
	S=bouge(j,S);
	
	printf("Fin slider\n");
	finir_affichage(S);
	free(j);
	free(S.murx); free(S.mury);free(S.murz);
	
	
	exit(0);
}
