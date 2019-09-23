/* O codigo aqui apresentado tem como base o programa 3.14
do livro de Robert Sedgewick, como exemplificado no exercicio
3.50 */

#include <stdlib.h>
#include "list.h" /* Header do exercicio 3.12 */

/* Com o uso de alocacao dinamica na memoria, a pre-alocacao
de uma lista vazia contendo o numero maximo da implementacao
faz-se inutil /*
/* link freelist; */

/*
  void initNodes(int N){
  int i;
  freelist = malloc((N+1)*(sizeof *freelist));
  for (i = 0; i < N+1; i++)
    freelist[i].next = &freelist[i+1];
  freelist[N].next = NULL;
  }
*/

link newNode(int i){
  link x = malloc(sizeof *x);
  x->item = i;
  x->next = NULL;

  return x;
}

void freeNode(link x){
  link t = x;

  x->next = Next(Next(x));
  free(t);
}

void insertNext(link x, link t){
  t->next = x->next;
  x->next = t;
}

link deleteNext(link x){
  link t = x->next;
  x->next = t->next;

return t;
}

link Next(link x){
  return x->next;
}

int Item(link x){
  return x->item;
}
