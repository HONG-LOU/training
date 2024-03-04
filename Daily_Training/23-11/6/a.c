#include <stdio.h>

int xfm(int x) {
  if (x <= 2) {
    return 1;
  }
  return xfm(x - 1) + xfm(x - 2);
}

int main () {
  int x;
  scanf("%d", &x);
  printf("%d", xfm(x));
  return 0;
}