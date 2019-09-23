#include <stdio.h>

int main () {

  int a, b;

  a = sizeof(int);
  b = sizeof(char);

  printf ("int = %02d bytes  char = %02d bytes  bit = 0.25 bytes", a, b);

  printf ("\n");
  return 0;
}
