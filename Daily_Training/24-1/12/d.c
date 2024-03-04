#include <stdio.h>

int c[15][15] = {0};

int main () {
  c[1][1] = 1;
  int i, j;

  for (i = 2; i < 15; i++) {
    for (j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }

  int n;
  scanf("%d", &n);

  for (i = 1; i <= n + 1; i++) {
    for (j = 0; j < n - i + 1; j++) {
      printf("  ");
    }

    for (j = 1; j <= i; j++) {
      printf("%4d", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}