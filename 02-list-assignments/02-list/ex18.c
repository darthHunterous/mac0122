#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

  int num, i, repetido = 0;
  char v[1000];

  srand(time(NULL));

  for (i = 1; i < 1000; i++) v[i] = '0';

  for (i = 0; repetido != 1; i++) {
    num = rand() % 1000 + 1;
    printf ("\n%d",num);
    if (v[num] == '1') {
      repetido = 1;
      i--;
    }
    if (v[num] == '0') v[num] = '1';
  }

  printf("Foram gerados %d numeros inteiros aleatorios nao repetidos de 1 a 999", i);

  printf("\n")  ;
  return 0;
}
