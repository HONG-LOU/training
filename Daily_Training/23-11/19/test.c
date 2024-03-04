#include <stdio.h>

int a[1010][1010] = {0};

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  int t;
  scanf("%d", &t);
  int i, j;
  while (t--) {
    int x, y, z, w;
    scanf("%d %d %d %d", &x, &y, &z, &w);
    if (x == 0) {
      a[y][z] = w;
      int i, j;
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          printf("%d ", a[i][j]);
        }
        printf("\n");
      }
    }
    else {
      long long ans = 0;
      int i;
      for (i = z; i <= w; i++) {
        ans += a[y][i];
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}