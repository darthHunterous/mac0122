#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]) {

  int i, N = atoi(argv[1]), M = atoi(argv[2]);
  Node x, t;

  x = malloc(sizeof *x);
  x->item = 1;
  t = x;
  x = x->next;

  for (i = 2, x = newNode(1); i <= N; i++) {
    x = x->next;
    x->next = newNode(i);
  }
  x->next = t;

  while (x != Next(x)) {
    for (i = 1; i < M; i++) x = Next(x);
    freeNode(x);
   }

   printf("%d\n", Item(x));

   printf("\n");
   return 0;
}
