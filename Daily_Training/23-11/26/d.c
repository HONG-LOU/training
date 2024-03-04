#include <stdio.h>

int a[1010][1010] = {0};

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  int k;
  scanf("%d", &k);
  int i, j;
  while (k--) {
    int op;
    scanf("%d", &op);
    if (op == 0) {
      int x, y, k;
      scanf("%d %d %d", &x, &y, &k);
      a[x][y] = k;
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          printf("%d ", a[i][j]);
        }
        printf("\n");
      }
    }
    else {
      int sum = 0;
      int row, l, r;
      scanf("%d %d %d", &row, &l, &r);
      for (i = l; i <= r; i++) {
        sum += a[row][i];
      }
      printf("%d\n", sum);
    }
  }
}