#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { float x; float y; } point;

float randFloat() {
  return 1.0*rand()/RAND_MAX;
}

float distance(point a, point b) {
  return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int main(int argc, char *argv[]) {


  float d = atof(argv[2]), dmin = 2, dis;
  int i, j, cnt = 0, N = atoi(argv[1]);
  point *a = malloc(N*(sizeof(*a)));
  point min1, min2;

  srand(time(NULL));

  for (i = 0; i < N; i++) {
    a[i].x = randFloat(); a[i].y = randFloat ();
  }

  for (i = 0; i < N; i++)
    for (j = i+1; j < N; j++){
      dis = distance(a[i], a[j]);
      if (dis < d) cnt++;
      if (dis < dmin) {
        dmin = dis;
        min1.x = a[i].x; min1.y = a[i].y;
        min2.x = a[j].x; min2.y = a[j].y;
      }
    }

  printf("%d edges shorter than %f\n", cnt, d);
  printf("\nclosest points are (%f, %f) and (%f, %f)", min1.x, min1.y, min2.x, min2.y);
  printf(": %f units far from each other", dmin);

  printf ("\n");
  return 0;
}
