#include <stdio.h>

int rmax[1010] = {0}, cmax[1010] = {0};

int a[1010][1010];

int max(int a, int b) {
  return a > b ? a : b;
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      rmax[i] = a[i][j];
      cmax[j] = a[i][j];
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      rmax[i] = max(a[i][j], rmax[i]);
      cmax[j] = max(a[i][j], cmax[j]);
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == rmax[i] && a[i][j] == cmax[j]) {
        printf("%d %d %d\n", a[i][j], i + 1, j + 1);
      }
    }
  }

  return 0;
}