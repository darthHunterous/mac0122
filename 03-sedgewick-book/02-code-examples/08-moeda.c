#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int heads (){
  return rand() < RAND_MAX/2;
}

int main(int argc, char *argv[]){

  int i, j, cnt;
  int N = atoi(argv[1]), M = atoi(argv[2]);
/* Para N receber 32 e M receber 1000 digitar ao executar o programa os valores
ou seja ./moeda 32 1000 */
  int *f = malloc((N+1)*sizeof(int));

  for (j = 0; j <= N; j++) f[j] = 0;

  srand (time(NULL));

  for (i = 0; i < M; i++, f[cnt]++)
    for (cnt = 0, j = 0; j <= N; j++)
      if (heads()) cnt++;

  for (j = 0; j <= N; j++) {
    printf("%2d ", j);
    for (i = 0; i < f[j]; i+=10) printf("*");
    printf("\n");
  }

  return 0;
}
