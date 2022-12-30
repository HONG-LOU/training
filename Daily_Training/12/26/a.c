#include <stdio.h>

int a[10101];
int c[600] = {0};

int main () {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    c[a[i]] += 1;
  }
  for (i = 0; i <= 500; i++) {
    if (c[i] > 0) {
      printf("%d %d\n", i, c[i]);
      break;
    }
  }
  for (i = 500; i >= 0; i--) {
    if (c[i] > 0) {
      printf("%d %d\n", i, c[i]);
      break;
    }
  }
  int max = 0;
  for (i = 0; i <= 500; i++) {
    if (c[i] > max) {
      max = c[i];
    }
  }
  for (i = 0; i <= 500; i++) {
    if (c[i] == max) {
      printf("%d %d ", i, c[i]);
    }
  }
  printf("\n");
  int p, q;
  int sum = 0;
  scanf("%d %d", &p, &q);
  for (i = p; i <= q; i++) {
    if (c[i] > 0) {
      sum += c[i];
    }
  }
  printf("%d", sum);
  return 0;
}