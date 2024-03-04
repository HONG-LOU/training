#include <stdio.h>

int a[15][15];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);

  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int ismax = 1;
      int k;
      for (k = 0; k < n; k++) {
        if (a[k][j] > a[i][j]) {
          ismax = 0;
        }
      }
      for (k = 0; k < m; k++) {
        if (a[i][k] > a[i][j]) {
          ismax = 0;
        }
      }
      if (ismax) {
        printf("%d %d %d\n", a[i][j], i + 1, j + 1);
      }
    }
  }

  return 0;
}