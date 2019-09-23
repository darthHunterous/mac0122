#include "point.h"

int colinear (point a, point b, point c) {
  if (((b.x <= a.x + 0.0001 && b.x >= a.x - 0.0001) ||
      (b.x <= c.x + 0.0001 && b.x >= c.x - 0.0001) ||
      (a.x <= c.x + 0.0001 && a.x >= c.x - 0.0001)) ||
     ((b.y <= a.y + 0.0001 && b.y >= a.y - 0.0001) ||
      (b.y <= c.y + 0.0001 && b.y >= c.y - 0.0001) ||
      (a.y <= c.y + 0.0001 && a.x >= c.y - 0.0001)))
      return 1;
      return 0;
}
