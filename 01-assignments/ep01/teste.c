#include "RAT.h"
#include <stdio.h>

int main () {

  Rational r;
  int x, y;

  scanf("%d %d", &x, &y);

  r = RATinit(x,y);
  RATshow(r);

  return 0;
}
