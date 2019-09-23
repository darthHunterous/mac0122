#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  int i, num, cont = 0;
  char v[1001];

  for (i = 0; i < 1001; i++) v[i] = '1';

  for (i = 1; argv[i] != 0; i++) {
    num = atoi(argv[i]);
    if (num < 1000 && v[num] == '1') cont++;
    if (v[num] == '1') v[num] = '0';
  }

  printf ("O numero de diferentes inteiros menores que 1000 foi %d", cont);

  printf ("\n");
  return 0;
}
