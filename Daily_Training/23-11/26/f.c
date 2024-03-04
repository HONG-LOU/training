#include <stdio.h>

int a[1010][1010] = {0};

int main () {
  int n;
  scanf("%d", &n);
  int i, j;
  while (n--) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (i = x1; i < x2; i++) {
      for (j = y1; j < y2; j++) {
        a[i][j] = 1;
      }
    }
  }
  int ans = 0;
  for (i = 0; i < 1010; i++) {
    for (j = 0; j < 1010; j++) {
      ans += a[i][j];
    }
  }
  printf("%d", ans);
  return 0;
}