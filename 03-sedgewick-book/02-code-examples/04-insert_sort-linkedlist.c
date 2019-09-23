#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* link;
struct node {int item; link next;};

int main (int argc, char *argv[]) {

  int i, N = atoi(argv[1]); /* i contador do for, N numero de inteiros
  aleatorios a serem gerados */
  struct node heada, headb;
  /* a aponta para o comeco da lista aleatoria gerada e b aponta para o comeco
  da lista organizada que sera formada */
  link t, u, x, a = &heada, b;
  /* ponteiro a recebe o endereco de heada. Caso o codigo fosse
  link a = heada estaria se referindo que o endereco que a aponta receberia
  o valor armazenado em heada, equivalente a int *a = heada.
  A grosso modo *a = &heada, significa que o ponteiro a passara a apontar
  para o local da memoria em que heada esta armazenado */
  /* t e' o ponteiro que percorrera a lista ligada */

  srand(time(NULL));

  /* laco que cria a lista ligada e a preenche com N numeros aleatorios.
  Ponteiro t e' inicializado a partir da posicao inicial da lista a (aleatorios
  desorganizados) */
  printf("\nLista A:\n");
  for (i = 0, t = a; i < N; i++) {
    t->next = malloc(sizeof *t); /* cria elemento apos a cabeca da lista */
    t = t-> next; /* move o ponteiro para o primeiro elemento efetivo da
    lista */
    t->next = NULL; /* proximo elemento da lista e' temporariamente considerado
    como nulo, ou seja, t encontra-se no ultimo elemento atual */
    t->item = rand() % 1000; /* o item do elemento atual recebe um inteiro
    aleatorio de 0 a 999 */
    printf("%d ", t->item);
  }

  b = &headb; /* ponteiro b passa a apontar para a cabeca da segunda lista */
  b->next = NULL; /* cabeca passa a ser o unico elemento da segunda lista
  ate o momento de execucao */

  for (t = a->next; t != NULL; t = u) {
  /* t aponta para o primeiro elemento apos a cabeca e percorre a primeira
  lista ate o final. */
    u = t->next; /* u aponta para o segundo elemento */
    for (x = b; x->next != NULL; x = x->next)
      if (x->next->item > t->item) break;
    t->next = x->next;
    x->next = t;
  }

  printf("\n\nLista B (organizada):\n");
  for(t = b->next; t != NULL; t = t->next) printf("%d ", t->item);

  printf ("\n\n");
  return 0;
}
