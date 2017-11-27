#include <uvsqgraphics.h>
#include "mes_types.h"
#define Taille_Case 50

void initialiser_affichage(SLIDER S) {
	init_graphics (Taille_Case*S.L,Taille_Case*S.H);
}

void afficher_grille(SLIDER S) {
	
	POINT p1,p2;
	p1.x=0; p1.y=0; p2.x=0; p2.y=Taille_Case*S.H;
	for (p2.x=Taille_Case;p2.x<S.L*Taille_Case;p2.x+=Taille_Case)
	{
		p1.x+=Taille_Case;
		draw_line(p1,p2,gray);
	}
	p1.x=0; p2.x=Taille_Case*S.L;
	for (p2.y=Taille_Case;p2.y<S.H*Taille_Case;p2.y+=Taille_Case)
	{
		p1.y+=Taille_Case;
		draw_line(p1,p2,gray);
	}
}

void afficher_murs(SLIDER S) {
	int n=0; POINT p1,p2;
	while (n!=S.N)
	{
		if (S.murz[n]==0){
			p1.x=(S.murx[n])*Taille_Case; p2.x=p1.x+Taille_Case;
			p1.y=p2.y=(S.mury[n])*Taille_Case+Taille_Case;
		}
		if (S.murz[n]==6){
			p1.x=(S.murx[n])*Taille_Case; p2.x=p1.x+Taille_Case;
			p1.y=p2.y=(S.mury[n])*Taille_Case;
		}
		if (S.murz[n]==3){
			p1.y=(S.mury[n])*Taille_Case; p2.y=p1.y+Taille_Case;
			p1.x=p2.x=Taille_Case+(S.murx[n])*Taille_Case;
		}
		if (S.murz[n]==9){
			p1.y=(S.mury[n])*Taille_Case; p2.y=p1.y+Taille_Case;
			p1.x=p2.x=(S.murx[n])*Taille_Case;
		}
		draw_line(p1,p2,red);
		n++;
	}
	//free(S.murx); free(S.mury); free(S.murz);
}

void afficher_le_slider(SLIDER S) {
	POINT p;
	p.x=S.x*Taille_Case+(Taille_Case/2);
	p.y=S.y*Taille_Case+(Taille_Case/2);
	draw_fill_circle(p,20,yellow);
	printf("affiche le slider \n");
}

void effacer_le_slider(SLIDER S) {
	POINT p;
	p.x=S.x*Taille_Case+(Taille_Case/2);
	p.y=S.y*Taille_Case+(Taille_Case/2);
	draw_fill_circle(p,20,noir);
}


void afficher_sortie(SLIDER S) {
	
	POINT p1,p2;
	p1.x=(S.px*Taille_Case); 
	p1.y=(S.py*Taille_Case);
	p2.x=p1.x+Taille_Case;
	p2.y=p1.y+Taille_Case;
	draw_fill_rectangle(p1,p2,white);
}


void afficher_slider (SLIDER S) {
	initialiser_affichage(S);
	afficher_grille(S);
	afficher_murs(S);
	afficher_le_slider(S);
	afficher_sortie(S);
}


void finir_affichage(SLIDER S) {
	wait_escape();
}
