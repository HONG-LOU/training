#include <stdio.h>

int a[1010];

int main () {
  int x;
  scanf("%d", &x);
  if (x < 0) {
    printf("-");
    x = -x;
  }
  int i;
  int len = 0;
  for (i = 0; x; i++, len++) {
    a[i] = x % 10;
    x /= 10;
  }
  for (i = 0; i < len; i++) {
    printf("%d", a[i]);
  }
  return 0;
}