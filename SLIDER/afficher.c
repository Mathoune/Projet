#include <uvsqgraphics.h>
#include "mes_types.h"

void
initialiser_affichage (SLIDER S) //Initialise la fenetre
{
  init_graphics (Taille_Case * S.L, Taille_Case * S.H);
}

void
afficher_grille (SLIDER S) //Affiche le quadrillage
{
  POINT p1, p2;
  p1.x = p1.y = p2.x = p2.y = 0;

  p2.y = Taille_Case * S.H;
  for (p2.x = Taille_Case; p2.x < S.L * Taille_Case; p2.x += Taille_Case)
    {
      p1.x += Taille_Case;
      draw_line (p1, p2, gray);
    }
  p1.x = 0;
  p2.x = Taille_Case * S.L;
  for (p2.y = Taille_Case; p2.y < S.H * Taille_Case; p2.y += Taille_Case)
    {
      p1.y += Taille_Case;
      draw_line (p1, p2, gray);
    }
}

void
afficher_murs (SLIDER S)//Affiche les murs
{
  int n = 0;
  POINT p1, p2;
  while (n != S.N)
    {
      if (S.murz[n] == 0)
	{
	  p1.x = (S.murx[n]) * Taille_Case;
	  p2.x = p1.x + Taille_Case;
	  p1.y = p2.y = (S.mury[n]) * Taille_Case + Taille_Case;
	}
      if (S.murz[n] == 6)
	{
	  p1.x = (S.murx[n]) * Taille_Case;
	  p2.x = p1.x + Taille_Case;
	  p1.y = p2.y = (S.mury[n]) * Taille_Case;
	}
      if (S.murz[n] == 3)
	{
	  p1.y = (S.mury[n]) * Taille_Case;
	  p2.y = p1.y + Taille_Case;
	  p1.x = p2.x = Taille_Case + (S.murx[n]) * Taille_Case;
	}
      if (S.murz[n] == 9)
	{
	  p1.y = (S.mury[n]) * Taille_Case;
	  p2.y = p1.y + Taille_Case;
	  p1.x = p2.x = (S.murx[n]) * Taille_Case;
	}
      draw_line (p1, p2, red);
      n++;
    }
}

void
afficher_le_slider (SLIDER S) //Affiche le Slider
{
  draw_fill_circle (S.ps, Taille_Case/2, yellow);
}

void
effacer_le_slider (SLIDER S) //Efface le Slider
{
  draw_fill_circle (S.ps, Taille_Case/2, noir);
}


void
afficher_sortie (SLIDER S) //Affiche la sortie
{

  POINT p1, p2;
  p1.x = (S.sx * Taille_Case);
  p1.y = (S.sy * Taille_Case);
  p2.x = p1.x + Taille_Case;
  p2.y = p1.y + Taille_Case;
  draw_fill_rectangle (p1, p2, white);
}

void
afficher_slider (SLIDER S) //Affiche tout
{
  initialiser_affichage (S);
  afficher_grille (S);
  afficher_murs (S);
  afficher_le_slider (S);
  afficher_sortie (S);
}

void
affichage (SLIDER S)
{
  afficher_grille (S);
  afficher_murs (S);
  afficher_le_slider (S);
}


void
finir_affichage (SLIDER S)
{
	fill_screen(black);
  POINT p; p.x=(S.L*Taille_Case)/2; p.y=(S.H*Taille_Case)/2;
  aff_pol_centre("FELICITATIONS !!!!",30,p,blanc);
  wait_escape ();
}
