#include <stdio.h>

int a[10101];

int main () {
  int n;
  scanf("%d", &n);
  a[1] = 1;
  a[2] = 2;
  long long sum = 0;
  int i;
  for (i = 3; i <= n; i++) {
    a[i] = (a[i - 1] + a[i - 2]) - 1;
  }
  for (i = 1; i <= n; i++) {
    sum += a[i];
  }
  printf("%lld", sum);
  return 0;
}