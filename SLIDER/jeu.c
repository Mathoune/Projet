#include <stdlib.h>
#include <uvsqgraphics.h>
#include <stdio.h>
#include "mes_types.h"

JEU ajout(JEU J, SLIDER s){
  JEU tmp = malloc(sizeof(struct JEU));
  tmp->s= s;
  tmp->suiv = J;
  return tmp;
}

Liste supprimeDebut(JEU j){
  JEU tmp;
  if(j != NULL){
    tmp = j;
    j = j->suiv;
    free(tmp);
  }
  return j;
}
