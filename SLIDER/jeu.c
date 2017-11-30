#include <stdlib.h>
#include <stdio.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"

LISTE ajout(LISTE l, SLIDER S)
{
  LISTE tmp = malloc(sizeof(struct element));
  tmp->S = S;
  tmp->suiv = l;
  return tmp;
}

LISTE libere_liste(LISTE l)
{
    while(l!=NULL)
	{					
		l->suiv=libere_liste(l->suiv);
		free(l);
	}		
	return NULL;
}

LISTE supp_un_element(LISTE l)
{
	LISTE ll;
	if(l != NULL){
	ll = l;
	l = l->suiv;
	free(ll);
  }
  return l;
}
LISTE retour_debut(LISTE l)
{ 
	LISTE ll=l;
	if (l==NULL) return NULL;
	if (l->suiv == NULL){
		free(l);
		return NULL;
	}
	
	while(l->suiv->suiv !=NULL)
	{					
		l=l->suiv;
	}	
		free(l->suiv);
		l->suiv=NULL;
		return ll;
}
SLIDER deplace(int a, SLIDER S)
{
	return S;
}

void bouge(SLIDER S)
{
	char c;
	int a,f; 
	POINT p;
	LISTE l=NULL; l=ajout(l,S);
	
	while ((S.y!=S.sy)||(S.x !=S.sx))
	{
		
		a=wait_key_arrow_clic(&c,&f,&p);
		SDL_EnableKeyRepeat(0,SDL_DEFAULT_REPEAT_INTERVAL);
		S.px=S.x*TAILLE_CASE+(TAILLE_CASE/2);
		S.py=S.y*TAILLE_CASE+(TAILLE_CASE/2);
			
			if(a == EST_FLECHE)
			{ 
				printf("1\n");
				if(f == FLECHE_GAUCHE){S=avance_gauche(S);}
				if(f == FLECHE_DROITE){S=avance_droite(S);}
				if(f == FLECHE_HAUTE){S=avance_haut(S);}
				if(f == FLECHE_BAS){S=avance_bas(S);}
				l=ajout(l,S);
				S.coups++;
			}
			if(a==2)
			{
				if(l!=NULL && c=='u')
				{
					effacer_le_slider(S);
					S=l->suiv->S; 
					l=supp_un_element(l); 
					afficher_le_slider(S);
				}
				if(l!=NULL && c=='r'){l=retour_debut(l);}
			}	
			printf("a= %d \n",a);
			a=0;
		
	}
}


