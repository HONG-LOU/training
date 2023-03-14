#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
  char s[100];
  strcpy(s, "不能吗？");
  printf("First%s\n", s);
  printf("Second不能吗？\n");
  char x[100] = "不能吗？";
  printf("Third%s\n", x);
  return 0;
}