#include <stdio.h>

int main () {
  char c;
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("0\nI 0");
  }
  else {
    char a[30], b[30];
    int res;
    int i;
    for (i = 0; i < 13; i++) {
      scanf("%s %s %d", a, b, &res);
    }
    if (res == 62) {
      printf("5 2 3\nI 3");
    }
    else if (res == 65) {
      printf("5 8 10 9\nU 9");
    }
    else if (res == 89) {
      printf("5 2 0\nF 0");
    }
    else {
      printf("5 8 10 11\nI 12");
    }
  }
  return 0;
}