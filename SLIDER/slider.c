#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "listes_memo.h"
#include "jeu.h"

int
main (int argc, char *argv[])
{
  printf ("Debut slider\n");
  SLIDER S;
  LISTE l = NULL;
  S = init_slider (argv[1]);
  afficher_slider (S);
	S.coups=0;
  l = bouge (S, l);
  finir_affichage (S);
  libere_murs (S);
  libere_liste (l);
  

  exit (0);
}
