#include <stdio.h>

int main () {
  int a[1000], i, j, N, primo;

  for (N = 3; N < 1000; N++){

  for (i = 2; i < N; i++) a[i] = 1;

  for (i = 2; i < N; i++)
    if (a[i])
      for (j = 2; i*j < N; j++) a[i*j] = 0;

  primo = 0;

  for (i = 2; i < N; i++)
    if (a[i]) primo++;

  printf ("\n%d ", N);

  for (i = 0; i < primo; i++) printf ("*");
}

  printf ("\n");
  return 0;
}
