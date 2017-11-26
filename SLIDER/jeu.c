#include <stdlib.h>
#include <stdio.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"

JEU ajout(JEU j, SLIDER s){
  JEU tmp = malloc(sizeof(SLIDER));
  tmp->s= s;
  tmp->suiv = j;
  return tmp;
}

JEU supprimeDebut(JEU j){
  if(j != NULL)
  {
    j = j->suiv;
  }
  return j;
}

JEU bouge(JEU j, SLIDER S)
{
	char c;
	int a,i,f; a=i=f=0;
	POINT p;
	while(i < 20)
	{
		a = wait_key_arrow_clic(&c, &f, &p);
		effacer_le_slider(S);
		if(f == FLECHE_GAUCHE){
		 S=avance_gauche(S);
		}
		if(f == FLECHE_DROITE){
		  S=avance_droite(S);
		}
		if(f == FLECHE_HAUT){
		  S=avance_haut(S);
		}
		if(f == FLECHE_BAS){
		  S=avance_bas(S);
		}
		j=ajout(j,S);
		
		afficher_le_slider(S);
	}
return j;
}


