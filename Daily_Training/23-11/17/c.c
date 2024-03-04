#include <stdio.h>

int main () {
  int n;
  scanf("%d", &n);
  int i, j;
  for (i = 1; i <= n; i += 2) {
    for (j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}