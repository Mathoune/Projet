#include <stdlib.h>
#include <stdio.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"

LISTE creer()
{
    LISTE *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->taille = 0;
        p_new->p_tete = NULL;
        p_new->p_queue = NULL;
    }
    return p_new;
}
LISTE ajout(LISTE *p_list, SLIDER S)
{
    if (p_list != NULL) 
    {
        struct element *p_new = malloc(sizeof *p_new);
        if (p_new != NULL) 
        {
            p_new->S = S; 
            p_new->p_suiv = NULL; 
            if (p_list->p_queue == NULL) 
            {
                p_new->p_prec = NULL;
                p_list->p_tete = p_new; 
                p_list->p_queue = p_new; 
            }
            else 
            {
                p_list->p_queue->p_suiv= p_new; 
                p_new->p_prec = p_list->p_queue; 
                p_list->p_queue = p_new; 
            }
            p_list->taille++; 
        }
    }
    return p_list; 
}
void libere_liste(LISTE **p_list)
{
    if (*p_list != NULL)
    {
        struct element *p_temp = (*p_list)->p_tete;
        while (p_temp != NULL)
        {
            struct node *p_del = p_temp;
            p_temp = p_temp->p_suiv;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}
LISTE supp_un_element(LISTE *p_list)
{
	
}
LISTE retour_debut(LISTE *p_list)
{
	
}
LISTE rajoute_un_element(LISTE *p_list)
{
	
}

SLIDER bouge(JEU j, SLIDER S)
{
	char c;
	int a,f; 
	POINT p;
	
	while ((S.y!=S.sy)||(S.x !=S.sx))
	{
		SDL_EnableKeyRepeat(0, SDL_DEFAULT_REPEAT_INTERVAL);
		a=wait_key_arrow_clic(&c,&f,&p);
		//wait_clic();
		S.px=S.x*TAILLE_CASE+(TAILLE_CASE/2);
		S.py=S.y*TAILLE_CASE+(TAILLE_CASE/2);
		effacer_le_slider(S);
			if(f == FLECHE_GAUCHE){
			 S=avance_gauche(S);
			}
			if(f == FLECHE_DROITE){
			  S=avance_droite(S);	
			}
			if(f == FLECHE_HAUTE){
			  S=avance_haut(S);
			}
			if(f == FLECHE_BAS){
			  S=avance_bas(S); 
			}
			if(j!=NULL&&c=='u')
			{
				j=supprimeDebut(j);
			}

		j=ajout(j,S);
		affichage(S);
	}
	return S;
}


