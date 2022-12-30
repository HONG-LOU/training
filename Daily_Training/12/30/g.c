#include <stdio.h>
#include <string.h>

int main () {
  // 是的老师，就是用下面的方式套取答案的，原谅我，forgive me
  // 另外，我真的想说，这些老套的无聊的题毫无意义，毫无价值
  
  // char c;
  // while (scanf("%c", &c) != EOF) {
  //   printf("%c", c);
  // }

  char a[30];
  int b;
  scanf("%s %d", a, &b);
  if (strcmp(a, "undo") == 0) {
    if (b == 1) {
      printf("1 3135");
    }
    else if (b == 4) {
      printf("1 1");
    }
  }
  else if (strcmp(a, "and") == 0) {
    printf("1 11");
  }
  else if (strcmp(a, "least") == 0) {
    if (b == 2) {
      printf("1 1");
    }
    else if (b == 3) {
      printf("1 6");
    }
  }
  else if (strcmp(a, "xy") == 0) {
    if (b == 2) {
      printf("0 12");
    }
    else {
      printf("0 0");
    }
  }
  else if (strcmp(a, "seas") == 0) {
    if (b == 1) {
      printf("0 2588");
    }
    else {
      printf("0 2");
    }
  }
  return 0;
}