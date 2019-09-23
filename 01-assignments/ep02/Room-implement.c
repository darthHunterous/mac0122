#include <stdlib.h>
#include "Room.h"

/* funcao que recebe um inteiro n, aloca um novo no da lista ligada
na memoria e devolve um ponteiro para sua localizacao */
Item* newNode(int n) {
  Item* x = malloc(sizeof *x);
  x->id = n;
  x->next = NULL;

  return x;
}
