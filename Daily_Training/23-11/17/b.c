#include <stdio.h>

int main () {
  double a, b;
  scanf("%lf %lf", &a, &b);
  double ans = 10;
  if (a <= 10 && a > 3) {
    ans += (a - 3.0) * 2;
  }
  if (a > 10) {
    ans += (7 * 2.0) + (a - 10) * 3.0;
  }
  int h = b / 5;
  ans += h * 2;
  printf("%.0f", ans);
  return 0;
}