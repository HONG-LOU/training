#include <stdio.h>

int main () {
  int x;
  scanf("%d", &x);
  if (x < 0) {
    printf("-");
    x = -x;
  }
  while (x) {
    printf("%d", x % 10);
    x /= 10;
  }
  return 0;
}