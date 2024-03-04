#include <stdio.h>
#include <string.h>

char s[1010];

int main () {
  scanf("%s", s);
  int len = strlen(s);
  int i;
  if (s[0] == '-') {
    printf("-");
    for (i = len - 1; i > 0; i--) {
      printf("%c", s[i]);
    }
  }
  else {
    for (i = len - 1; i >= 0; i--) {
      printf("%c", s[i]);
    }
  }
  return 0;
}