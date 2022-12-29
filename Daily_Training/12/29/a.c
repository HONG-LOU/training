#include <stdio.h>

int main () {
  printf("hello world\n");
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);
  char s[30];
  printf("hello world!\n");
  while (scanf("%s", s) != EOF) {
    printf("%s\n", s);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}