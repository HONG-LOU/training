#include <stdio.h>

int main () {
  int n;
  scanf("%d", &n);
  int m;
  scanf("%d", &m);
  if (m <= 10) {
    int a[101010];
    int c = 0;
    do {
      a[c++] = n % m;
      n /= m;
    } while (n != 0);
    int i, j;
    for (i = 0; i < c - 1; i++) {
      for (j = i + 1; j < c; j++) {
        if (a[j] > a[i]) {
          int temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
    }
    for (i = 0; i < c; i++) {
      printf("%d", a[i]);
    }
  }
  else {
    char a[101010];
    int c = 0;
    do {
      char p;
      int cnt = n % m;
      if (cnt < 10) {
        p = (char) (cnt + '0');
      }
      else {
        p = (char) ('A' + cnt - 10);
      }
      a[c++] = p;
      n /= m;
    } while (n != 0);
    int i, j;
    for (i = 0; i < c - 1; i++) {
      for (j = i + 1; j < c; j++) {
        int x, y;
        if (a[i] >= 'A' && a[i] <= 'F') {
          x = a[i] - 'A' + 10;
        }
        else {
          x = a[i] - '0';
        }
        if (a[j] >= 'A' && a[j] <= 'F') {
          y = a[j] - 'A' + 10;
        }
        else {
          y = a[j] - '0';
        }
        if (y > x) {
          char temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
    }
    for (i = 0; i < c; i++) {
      printf("%c", a[i]);
    }
  }
  return 0;
}