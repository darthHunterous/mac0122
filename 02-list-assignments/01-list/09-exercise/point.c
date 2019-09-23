#include <math.h>
#include "point.h"
#include <stdio.h>

point pol_cart (point a, polar b) {

  b.theta *= (double) M_PI/180;

  a.x = (double) b.r * cos (b.theta);
  a.y = (double) b.r * sin (b.theta);

  return a;
}

polar cart_pol (point a, polar b) {

  b.r = sqrt (a.x * a.x + a.y * a.y);


  if (a.x > 0 && a.y > 0) b.theta = acos (a.x/b.r)*180/M_PI;
  if (a.x > 0 && a.y < 0) b.theta = (double) 360 - acos (a.x/b.r)*180/M_PI;
  if (a.x < 0 && a.y < 0) b.theta = (double) 180 + acos (a.x/b.r)*180/M_PI;
  if (a.x < 0 && a.y > 0) b.theta = (double) acos (a.x/b.r)*180/M_PI;

  if (a.x == 0) b.theta = asin (a.y/b.r)*180/M_PI;
  
  return b;
}
