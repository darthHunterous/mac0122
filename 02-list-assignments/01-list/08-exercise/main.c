#include <stdio.h>
#include "point.h"

int main () {

  point a, b, c;

  printf ("Insira os 3 pontos: ");
  scanf ("%f %f %f %f %f %f", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

  if (colinear(a, b, c)) printf ("\nOs pontos inseridos sao colineares\n");
  else printf ("\nOs pontos inseridos nao sao colineares\n");

  return 0;
}
