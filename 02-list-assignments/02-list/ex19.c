#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

  int num, i, j, preenchido = 0;
  char v[1000];

  srand(time(NULL));

  for (i = 1; i < 1000; i++) v[i] = '0';

  for (i = 0; !preenchido; i++) {
    num = rand() % 1000 + 1;
    if (v[num] == '0') v[num] = '1';
    if (i > 999)
      for (j = 0, preenchido = 1; j < 1000; j++)
        if (v[j] == '0') preenchido = 0;
  }

  printf("Foram gerados %d numeros inteiros aleatorios ate o preenchimento", i);

  printf("\n")  ;
  return 0;
}
