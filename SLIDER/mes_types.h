
#define TAILLE_CASE 50


struct slider {
	int L,H; // Largeur et hauteur de la grille
	int x,y; // Position du slider
	int px,py; // Position sortie
	int N; // Nombre de murs
	int *murs_x; //Positions des murs en x
	int *murs_y; //Positions des murs en y
};

typedef struct slider SLIDER;
