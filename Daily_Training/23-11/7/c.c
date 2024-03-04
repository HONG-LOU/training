#include <stdio.h>

void reverse(int x) {
  if (x == 0) {
    return;
  }
  int c = x % 10;
  printf("%d", c);
  reverse(x / 10);
}

int main () {
  int x;
  scanf("%d", &x);
  if (x < 0) {
    printf("-");
    x = -x;
  }
  reverse(x);
  return 0;
}