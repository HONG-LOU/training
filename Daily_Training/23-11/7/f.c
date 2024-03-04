#include <stdio.h>

int main () {
  int x = 11;
  printf("%d\n", (x++*1/3));
  printf("%d", (++x*1/3));
  return 0;
}