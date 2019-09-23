#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "point.h"

int main () {

  int n, i;
  double soma = 0;
  triangle l;

  printf ("\nInsira a quantidade de triangulos aleatorios: ");
  scanf ("%d", &n);

  srand (time(NULL));

  for (i = 0; i < n; i++) {
    l = random_t();
    soma += area(l);
  }

  printf ("\nA media das areas dos triangulos eh %lf", (double)soma/n);

  return 0;
}
