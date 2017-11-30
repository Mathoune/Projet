#include <uvsqgraphics.h>
#define TAILLE_CASE 50


struct slider {
	int L,H;	 // Largeur et hauteur de la grille
	int x,y; 	// Position du slider en nombre de case
	int px, py;	 // Position du slider en coordonnées
	int sx,sy;   // Position sortie
	int N; 		// Nombre de murs
	int *murx;
	int *mury;
	int *murz;
	int coups;
};
typedef struct slider SLIDER;


struct element{
  SLIDER S;
  struct element *suiv;
};
typedef struct element *LISTE;
