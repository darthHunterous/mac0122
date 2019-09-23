#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;

struct node { int item; link next; };

int main(int argc, char *argv[]) {
    /* A entrada do programa na linha de comando deve ser feita coms valores
    pretendidos para M, ou seja, 2,3,5 e 10 */
    int i, j, N, M[4];
    link t = malloc(sizeof *t), x;
    t->item = 1; t->next = t;

    /* Armazena os valores passados na linha de comando para M em um vetor */
    for (i = 0; i < 4; i++) M[i] = atoi(argv[i+1]);

    printf("\nValores obtidos para a funcao de Josephus: ");
    printf("\n\n  M\\N |   1E+3   |   1E+4   |   1E+5   |   1E+6   |");
    printf("\n---------------------------------------------------");

    for (j = 0; j < 4; j++) {
      printf("\n  %02d  |", M[j]);
      for (N = 1E+3; N <= 1E+6; N *= 10) {
        x = t;
        for (i = 2; i <= N; i++) {
          x = (x->next = malloc(sizeof *x));
          x->item = i;
        }
        x->next = t;

        while (x != x->next) {
          for (i = 1; i < M[j]; i++) x = x->next;
          x->next = x->next->next;
        }

        /* Otimiza a formatacao da saida baseada nos possiveis valores que
        a funcao de Josephus pode tomar */
        printf("  %06d  |", x->item);
      }
    }

    printf("\n");
    return 0;
}
