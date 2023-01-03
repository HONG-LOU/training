#include <stdio.h>

int main () {
  freopen("in.txt", "r", stdin);
  char c;
  char s[100];
  int i = 0;
  while (scanf("%c", &c) != EOF) {
    s[i++] = c;
  }
  int j;
  for (j = 0; j < i; j++) {
    if (s[j] == '\n') {
      printf("\\n");
      continue;
    }
    printf("%c", s[j]);
  }
  fclose(stdin);
  return 0;
}