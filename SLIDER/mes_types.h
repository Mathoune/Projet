
#define TAILLE_CASE 50


struct slider {
	int L,H; // Largeur et hauteur de la grille
	int x,y; // Position du slider
	int px,py; // Position sortie
	int N; // Nombre de murs
	int *murx;
	int *mury;
	int *murz;
	int coups;
};

typedef struct slider SLIDER;

struct jeu {
	SLIDER s;
		struct jeu* suiv;
};
typedef struct jeu JEU;
