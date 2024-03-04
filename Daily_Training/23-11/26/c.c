#include <stdio.h>

int a[10][10] = {0};
int b[10][10] = {0};

int main () {
  int n;
  scanf("%d", &n);
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int m;
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  for (i = 0; i <= n - m; i++) {
    for (j = 0; j <= n - m; j++) {
      int l, k;
      int flag = 1;
      for (k = 0; k < m && flag; k++) {
        for (l = 0; l < m; l++) {
          if (b[k][l] != a[i + k][j + l]) {
            flag = 0;
            break;
          }
        }
      }
      if (flag) {
        printf("%d,%d", i + 1, j + 1);
        return 0;
      }
    }
  }
  printf("-1");
  return 0;
}