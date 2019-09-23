#include <stdio.h>
#include <time.h>

int main () {

  clock_t begin = clock();
  int a[1000000], i, j, N;

  for (N = 1000; N <= 1000000; N*=10){

  for (i = 2; i < N; i++) a[i] = 1;

  for (i = 2; i < N; i++)
    if (a[i])
      for (j = 2; i*j < N; j++) a[i*j] = 0;

  for (i = 2; i < N; i++)
    if (a[i])
      printf ("%06d ", i);

  printf ("\n\n");
}

  clock_t end = clock();
  double time_spent = (double) (end-begin)/CLOCKS_PER_SEC;
  printf ("\n\n\nO tempo gasto foi %lfs", time_spent);
  /* Tempo gasto == 0.070379s */

  printf ("\n");
  return 0;
}
