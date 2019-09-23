#include <stdio.h>
#include <math.h>
#include "point.h"

int main () {

  int escolha;
  point a;
  polar b;

  printf ("\nInsira 1 para transformar de Polar para Cartesiano");
  printf (" ou insira 2 para transformar de Cartesiano para Polar: ");
  scanf ("%d", &escolha);

  if (escolha == 1) {
    printf ("\nInsira a coordenada polar a ser convertida, com angulo em graus: ");
    scanf ("%lf %lf", &b.r, &b.theta);
    a.x = 0; a.y = 0;
    a = pol_cart (a, b);
    printf ("\nO ponto tem coordenadas cartesianas (%lf, %lf)\n", a.x, a.y);
  }
  else {
    printf ("\nInsira a coordenada cartesiana a ser convertida, com angulo em graus: ");
    scanf ("%lf %lf", &a.x, &a.y);
    b.r = 0; b.theta = 0;
    b = cart_pol (a, b);
    printf ("\nO ponto tem coordenadas polares (%lf, %lf), graus\n", b.r, b.theta);
  }

  return 0;
}
