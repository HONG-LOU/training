#include <stdio.h>

void pri(int x) {
  if (x == 0) {
    return;
  }
  // printf("%d\n", x);
  pri(x - 1);
  printf("%d\n", x);
}

int main () {
  pri(5);
  return 0;
}