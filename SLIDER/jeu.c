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

SLIDER bouge(JEU j, SLIDER S)
{
	char c;
	int a,f; 
	POINT p;
	
	while ((S.y!=S.sy)||(S.x !=S.sx))
	{
		a=wait_key_arrow_clic(&c,&f,&p);
		wait_clic();
		effacer_le_slider(S);
		
			if(f == FLECHE_GAUCHE){
			 S=avance_gauche(S);
			 printf("gauche");
			}
			if(f == FLECHE_DROITE){
			  S=avance_droite(S);	
			  printf("droite");  
			}
			if(f == FLECHE_HAUTE){
			  S=avance_haut(S);
			  printf("haut");
			}
			if(f == FLECHE_BAS){
			  S=avance_bas(S); 
			  printf("bas");
			}

		j=ajout(j,S);
		
		afficher_le_slider(S);	
	}
	return S;
}


