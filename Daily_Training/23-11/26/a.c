#include <stdio.h>

int a[20][20] = {0};

int min(int a, int b) {
  return a > b ? b : a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main () {
  int n;
  scanf("%d", &n);
  int i, j;
  for (i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // get the smallest value
  int minv = (int) 1e9;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      minv = min(minv, a[i][j]);
    }
  }

  // get the biggest value
  int maxv = - (int) 1e9;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      maxv = max(maxv, a[i][j]);
    }
  }

  // get the sum;
  int sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sum += a[i][j];
    }
  }

  // take place 
  for (i = 0; i < n; i++) {
    a[i][0] = minv;
    a[0][i] = minv;
    a[n - 1][i] = minv;
    a[i][n - 1] = minv;
  }
  
  a[n / 2][n / 2] = maxv;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0 || i == n - 1 || j == 0 || j == n - 1 || (i == n / 2 && j == n / 2)) {
        printf("%5d", a[i][j]);
        continue;
      }
      else {
        printf("%5d", sum);
      }
    }
    printf("\n");
  }

  return 0;
}