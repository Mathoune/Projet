#include "mes_types.h"
#include "afficher.h"

LISTE
ajout (LISTE l, SLIDER S)
{
  LISTE tmp = malloc (sizeof (struct element));
  tmp->ps.x = S.ps.x;
  tmp->ps.y = S.ps.y;
  tmp->suiv = l;
  return tmp;
}

LISTE
libere_liste (LISTE l)
{
LISTE ll;
  while (l != NULL)
    {
     ll = l;
      l = l->suiv;
      free (ll);
    }
    free(l);
  return NULL;
}

LISTE
supp_un_element (LISTE l)
{
  LISTE ll;
  if (l->suiv!= NULL)
    {
      ll = l;
      l = l->suiv;
      free (ll);
    }
  return l;
}

LISTE
retour_debut (LISTE l)
{
  LISTE ll;
  while (l->suiv != NULL)
    {
      ll = l;
      l = l->suiv;
      free (ll);
    }
  return l;
}

void
libere_murs (SLIDER S)
{
	
}

LISTE
retour (LISTE l, SLIDER S, int c)
{
	effacer_le_slider(S);
  if (l != NULL && c == 'U')	//Pour faire le undo
    {
      l = supp_un_element (l);
    }
  if (l != NULL && l->suiv != NULL && c == 'R')	//Pour recommencer
    {
      l = retour_debut (l);
    }
   S.ps=l->ps;
  return l;
}
