#include <stdio.h>

int main () {

  int a[99], i;

  for (i = 0; i < 99; i++) {
    a[i] = 98 - i;
    if (i != 0 && i % 15 == 0) printf ("\n");
    printf ("%02d ", a[i]);
  }

  printf ("\n\n");

  for (i = 0; i < 99; i++) {
    a[i] = a[a[i]];
    if (i != 0 && i % 15 == 0) printf ("\n");
    printf ("%02d ", a[i]);
  }

  printf ("\n");
  return 0;
}
