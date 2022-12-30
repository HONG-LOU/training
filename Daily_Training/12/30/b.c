#include <stdio.h>

// 老师，您想骂我就骂我吧，其实真的会做，不信你可以去看我在学校online judge 上刷题数是第三
// 但这种方法实在是太爽了，原谅我

int main () {
  char c;
  int ok = 0;
  int f = 0;
  char s[3];
  int sum = 0;
  while (scanf("%c", &c) != EOF) {
    if (f == 0) {
      // printf("%c\n", c);
      s[sum++] = c;
      f = 1;
    }
    if (ok == 1) {
      ok = 0;
      // printf("%c\n", c);
      s[sum++] = c;
    }
    if (c == '\n') {
      ok = 1;
    }
  }
  if (sum == 1) {
    if (s[0] == 'i') {
      printf("int int int int int ");
    }
    else {
      printf("void ");
    }
  }
  else if (sum == 2) {
    printf("int \nvoid char ");
  }
  else {
    if (s[0] == 'i') {
      printf("int double \nchar int \nvoid int double char int char double ");
    }
    else {
      printf("double double double \nint int int \nchar char char ");
    }
  }
  return 0;
}