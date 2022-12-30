#include <stdio.h>

double a[1010][2];

int main () {
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", &a[i][0], &a[i][1]);
  }
  int j;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i][0] > a[j][0]) {
        double temp = a[i][0];
        a[i][0] = a[j][0];
        a[j][0] = temp;
        temp = a[i][1];
        a[i][1] = a[j][1];
        a[j][1] = temp;
      }
    }
  }
  double sum = 0;
  int cnt = 0;
  for (i = 0; i < n && m > 0; i++) {
    if (m >= a[i][1]) {
      sum += (a[i][1] * a[i][0]);
      m -= a[i][1];
    }
    else {
      sum += (m * a[i][0]);
      m = 0;
    }
  }
  printf("%.1lf", sum);
  return 0;
}