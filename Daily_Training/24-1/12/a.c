/**
 *    author:  HONG-LOU
 *    created: 2024-01-14 13:55:12
**/
#include <stdio.h>

int main () {

  int d, h, m;

  scanf("%d %d %d", &d, &h, &m);
  
  int sum = (d * 24 * 60) + (h * 60) + m;
  printf("%d", sum);
  return 0;
}