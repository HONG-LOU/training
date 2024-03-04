#include <stdio.h>

double p(double n, double x)
{
  if (n == 0)
  {
    return 1.0;
  }
  else if (n == 1)
  {
    return x;
  }
  else
  {
    return ((2 * n - 1) * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
  }
}

int main()
{
  double n, x;
  scanf("%lf %lf", &n, &x);
  printf("%.2f", p(n, x));
  return 0;
}