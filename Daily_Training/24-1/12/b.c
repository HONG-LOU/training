#include <stdio.h>

int main () {

  int x;
  scanf("%d", &x);

  int ans = 0;

  while (x > 0) {
    ans++;
    x = x / 10;
  }

  printf("%d", ans);
  return 0;
}