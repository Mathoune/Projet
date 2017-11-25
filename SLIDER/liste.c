#include <stdlib.h>
#include <uvsqgraphics.h>
#include <stdio.h>
#include "mes_types.h"

Liste ajoutDebut(Liste l, POINT p){
  Liste tmp = malloc(sizeof(struct element));
  tmp->p = p;
  tmp->suiv = l;
  return tmp;
}
