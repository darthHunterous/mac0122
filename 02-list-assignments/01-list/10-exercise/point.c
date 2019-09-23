#include "point.h"
#include <stdlib.h>

double area (triangle l) {

  double det;

  det = l.a.x*l.b.y+l.a.y*l.c.x+l.c.y*l.b.x-l.b.y*l.c.x-l.a.y*l.b.x-l.a.x*l.c.y;
  if (det<0) det *= -1;

  return (double) det/2;
}

triangle random_t (){
  triangle l;

  l.a.x = (double) rand()/RAND_MAX; l.a.y = (double) rand()/RAND_MAX;
  l.b.x = (double) rand()/RAND_MAX; l.b.y = (double) rand()/RAND_MAX;
  l.c.x = (double) rand()/RAND_MAX; l.c.y = (double) rand()/RAND_MAX;

  return l;
}
