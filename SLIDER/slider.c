#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "listes_memo.h"
#include "jeu.h"
#include "editeur.h"

int
main (int argc, char *argv[])
{
  printf ("Debut slider\n");

  SLIDER S;
  LISTE l = NULL;

  if (argv[1][0] == '-' && argv[1][1] == 'c')
    {
      int L, H;
      
      L = atoi (argv[2]);
      H = atoi (argv[3]);
      S=editeur (S, L, H, argv[4]);
    }
    
  if (argv[1][0] != '-' || argv[1][1] != 'c')
    { 
	 S = init_slider (argv[1]);
     afficher_slider (S);
     }
     
     l = bouge (S, l);
     finir_affichage (S);
     libere_murs (S);
     libere_liste (l); 
  wait_escape ();
  exit (0);
}
