#include <stdio.h>

int isP (int x) {
  if (x <= 3) {
    return 1;
  }
  int i;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int re (int x) {
  int y = 0;
  while (x) {
    y = y * 10 + (x % 10);
    x /= 10;
  }
  return y;
}

int main () {
  int n;
  scanf("%d", &n);
  if (isP(n) == 1 && isP(re(n)) == 1) {
    printf("yes\n");
  }
  else {
    printf("no\n");
  }
  return 0;
}
