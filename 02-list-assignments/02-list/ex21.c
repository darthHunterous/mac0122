#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Retorna se saiu cara ou nao com base na probabilidade p de se sair cara
  ou seja, se p = 2, ha 1/2 chance de cara, se p = 6 ha 1/6 de chance
  generalizando: 1/p chance de sair cara */
int heads (int p){
  return rand() < RAND_MAX/p;
}

int main(int argc, char *argv[]){

  int i, j, cnt, p = atoi(argv[3]);
  int N = atoi(argv[1]), M = atoi(argv[2]);
/* Para N receber 32 e M receber 1000 digitar ao executar o programa os valores
ou seja ./moeda 32 1000 */
  int *f = malloc((N+1)*sizeof(int));

  for (j = 0; j <= N; j++) f[j] = 0;

  srand (time(NULL));

  for (i = 0; i < M; i++, f[cnt]++)
    for (cnt = 0, j = 0; j <= N; j++)
      if (heads(p)) cnt++;

  for (j = 0; j <= N; j++) {
    printf("%2d ", j);
    for (i = 0; i < f[j]; i+=10) printf("*");
    printf("\n");
  }

  return 0;
}
