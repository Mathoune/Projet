#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "listes_memo.h"
#include "jeu.h"
#include "editeur.h"
#include "lire_dossier.h"

int
main (int argc, char *argv[])
{
  printf ("Debut slider\n");

  SLIDER S;
  LISTE l = NULL;
  char *c;
  c = "dir_slider";

  if (argv[1][0] == '-' && argv[1][1] == 'c')
     {
     int L, H;

     L = atoi (argv[2]);
     H = atoi (argv[3]);
     S = editeur (S, L, H, argv[4]);
     partie(S,argv [4],l);
     } 
  if (strcmp (argv[1], c) == 0)
    {
      ouvrir_dir (S,l);
    }
    
   if (strcmp(argv[1],"-c")!=0)
     {
     partie (S,argv[1],l);
	 }
	
   
	exit (0);
}
