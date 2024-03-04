#include <stdio.h>

int ans = 1;

void plus(int x) {
  if (x == 1) {
    return;
  }
  ans *= x;
  plus(x - 1);
}

int main () {
  plus(5);
  printf("%d", ans);
  return 0;
}