#include <uvsqgraphics.h>

#include "mes_types.h"


void initialiser_affichage(SLIDER S) {
	init_graphics (50*S.L,50*S.H);
}

void afficher_grille(SLIDER S) {
	
	POINT p1,p2;
	p1.x=0; p1.y=0; p2.x=0; p2.y=50*S.H;
	for (p2.x=50;p2.x<S.L*50;p2.x+=50)
	{
		p1.x+=50;
		draw_line(p1,p2,white);
	}
	p1.x=0; p2.x=50*S.L;
	for (p2.y=50;p2.y<S.H*50;p2.y+=50)
	{
		p1.y+=50;
		draw_line(p1,p2,white);
	}
}

void afficher_murs(SLIDER S) {
	int n=0; POINT p1,p2;
	while (n!=S.N)
	{
		if (S.murz[n]==0){
			p1.x=(S.murx[n])*50; p2.x=p1.x+50;
			p1.y=p2.y=(S.mury[n])*50;
		}
		if (S.murz[n]==3){
			p1.y=(S.mury[n])*50; p2.y=p1.y+50;
			p1.x=p2.x=50+(S.murx[n])*50;
		}
		if (S.murz[n]==6){
			p1.x=(S.murx[n])*50; p2.x=p1.x+50;
			p1.y=p2.y=(S.mury[n])*50;
		}
		if (S.murz[n]==9){
			p1.y=(S.mury[n])*50; p2.y=p1.y+50;
			p1.x=p2.x=(S.murx[n])*50;
		}
		draw_line(p1,p2,red);
		n++;
	}
}

void afficher_le_slider(SLIDER S) {
	
}

void afficher_sortie(SLIDER S) {
}


void afficher_slider (SLIDER S) {
	afficher_grille(S);
	afficher_murs(S);
	afficher_le_slider(S);
	afficher_sortie(S);
}


void finir_affichage(SLIDER S) {
	wait_escape();
}
