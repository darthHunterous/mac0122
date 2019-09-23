#include <stdlib.h>
#include "STACK.h"

/* define o endereco do topo da lista (cabeca) */
static link top;

/* inicializar a lista, com o topo como ponteiro nulo */
void STACKinit() {
  top = NULL;
}

/* cria um novo elemento na pilha, devolvendo seu endereco.
Recebe um valor e o endereco do proximo elemento a ser apontado */
link STACKnew(int item, link next){
  link x = malloc(sizeof *x);
  x->value = item;
  x->next = next;

  return x;
}

/* retorna o valor do elemento no topo da pilha */
int STACKpop() {
  int item = top->value;
  link z = top->next;
  free(top);
  top = z;

  return item;
}

/* insere o valor item no topo da pilha */
void STACKpush(int item) {
  top = STACKnew(item, top);
}
