#include <stdio.h>

int main () {
  int n;
  scanf("%d", &n);
  while (n > 1) {
    int x;
    for (x = 2; ; x++) {
      if (n % x == 0) {
        printf("%d ", x);
        n /= x;
        break;
      }
    }
  }
  return 0;
}