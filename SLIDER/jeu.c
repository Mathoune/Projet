#include <stdlib.h>
#include <uvsqgraphics.h>
#include <stdio.h>
#include "mes_types.h"

JEU ajout(JEU j, SLIDER s){
  JEU tmp = malloc(sizeof(struct JEU));
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



