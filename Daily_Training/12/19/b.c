#include <stdio.h>

#define N 20

int a[N][N], b[N][N];

int main () {
  int n;
  scanf("%d", &n);
  int i, j;
  char c;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  scanf("%c", &c);
  while (c != '#') {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%5d", b[i][j]);
      }
      puts("");
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (c == '+') b[i][j] += a[i][j];
        else b[i][j] -= a[i][j];
      }
    }
    scanf("%c", &c);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%5d", b[i][j]);
    }
    printf("\n");
  }
  return 0;
}