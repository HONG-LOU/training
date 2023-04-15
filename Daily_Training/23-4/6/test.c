/**
 *    author:  HONG-LOU
 *    created: 2023-04-06 17:40:53
**/
#include <stdio.h>

int a[101][101] = {0};

int main () {
  int n, i, j, k;
  while (1) {
    printf("Please enter the number of rows : ");
    scanf("%d", &n);
    if ((n != 0) && (n <= 100) && (n % 2 != 0)) {
      break;
    }
    printf("Error input !!!\n");
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      a[i][j] = 0;
    }
  }
  j = n / 2 + 1;
  i = 1;
  a[i][j] = 1;
  for (k = 2; k <= n * n; k++) {
    i = i - 1;
    j = j + 1;
    if ((i < 1) && (j > n)) {
      i = i + 2;
      j = j - 1;
    }
    else {
      if (i < 1)
        i = n;
      if (j > n)
        j = 1;
    }
    if (a[i][j] == 0) {
      a[i][j] = k;
    }
    else {
      i = i + 2;
      j = j - 1;
      a[i][j] = k;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      printf("%-5d", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
