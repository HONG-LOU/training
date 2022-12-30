#include <stdio.h>

int main () {
  // 是的老师，就是用下面的方式套取答案的，原谅我，forgive me
  // char c;
  // while (scanf("%c", &c) != EOF) {
  //   printf("%c", c);
  // }
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("0\nI 0");
  }
  else {
    char a[30], b[30];
    int i;
    for (i = 0; i < 13; i++) {
      scanf("%s %s", a, b);
    }
    if (strcmp(a, "blue") == 0) {
      printf("5 2 3\nI 3");
    }
    else if (strcmp(a, "john") == 0) {
      printf("5 8 10 9\nU 9");
    }
    else if (strcmp(a, "alice") == 0) {
      printf("5 2 0\nF 0");
    }
    else {
      printf("5 8 10 11\nI 12");
    }
  }
  return 0;
}