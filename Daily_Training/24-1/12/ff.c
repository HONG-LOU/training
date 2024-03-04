#include <stdio.h>

int a[1010], b[1010], c[1010101];

int main () {
  int n, m;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    c[a[i]] = 1;
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);

    if (c[b[i]]) {
      c[b[i]] = 2;
    }
  }

  for (i = 0; i < n; i++) {
    if (c[a[i]] == 2) {
      printf("%d ", a[i]);
      c[a[i]] = 3;
    }
  }

  return 0;
}