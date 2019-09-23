typedef struct node* link;
struct node { int item; link next;};

link reverse (link x) { /* link x e' o ponteiro que denota o comeco da
lista ligada */

  link t, y = x, r = NULL;
  /* y seria o primeiro elemento da lista a ser invertida e t o link que aponta
  para o no seguinte. r recebe nulo por anteceder a posicao de y, ou seja,
  antes do comeco da lista em si. Apos a inversao, r se torna o link do ultimo
  no da lista ligada, ou seja, que nao aponta para elemento algum */

  /* enquanto y nao ultrapassar o ultimo elemento da lista, cujo link aponta
  para nada, ou seja, enquanto y nao se tornar o ponteiro que aponta para nada,
  o loop continua. */
  while (y != NULL) {
    t = y->next; /* t aponta para o item seguinte a y, inicializado como o
    primeiro da lista*/
    y->next = r; /* determina que o no do primeiro elemento da lista na ordem
    convencional aponte para o ponteiro nulo, uma vez que sera o ultimo
    elemento da lista invertida */
    r = y; /* r deixa de apontar para o vazio e passa a apontar para o primeiro
    elemento */
    y = t; /* y passa a apontar para o segundo elemento da lista */
  }

  return r; /* retorna r que percorreu a lista inteira ate se tornar o no'
  inicial da lista apos a inversao */
}
