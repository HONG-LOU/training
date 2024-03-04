#include <stdio.h>

int plus (int x) {
  if (x == 1) {
    return 1;
  }
  else {
    return plus(x - 1) * x;
  }
}

int main () {
  int x;
  scanf("%d", &x);
  printf("%d", plus(x));
  return 0;
}