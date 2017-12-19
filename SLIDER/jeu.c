#include <stdlib.h>
#include <stdio.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"
#include "listes_memo.h"
int
sortie (SLIDER S)		//Test si le Slider est dans la sortie
{
  S.sx = S.sx * Taille_Case + Demi_Case;
  S.sy = S.sy * Taille_Case + Demi_Case;
  if (S.ps.x == S.sx && S.ps.y == S.sy)
    return 0;
  return 1;
}


LISTE
bouge (SLIDER S, LISTE l)	//Gere le mouvement du Slider
{
  char c;
  int a, f;
  POINT p;
  l = ajout (l, S);
  while (sortie (S))
    {
      a = wait_key_arrow_clic (&c, &f, &p);
      SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
      S.x = (S.ps.x - Demi_Case )/ Taille_Case;
      S.y = (S.ps.y - Demi_Case) / Taille_Case;

      if (a == EST_FLECHE)
	{
	  S = deplace (f, S);
	  l = ajout (l, S);
	}
      if (a == EST_TOUCHE)
	{
	  l = retour (l, S, c);
	  S.ps = l->ps;
	  afficher_le_slider (S);

	}
      S.coups++;
    }
  return l;
}
