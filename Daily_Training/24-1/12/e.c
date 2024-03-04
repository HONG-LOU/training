#include <stdio.h>
#include <string.h>

char s[10101];

void stringNx (char *a) {
  char cnt[10101];
  int len = strlen(a);
  int i;
  for (i = 0; i < len; i++) {
    cnt[i] = a[len - i - 1];
  }
  strcpy(a, cnt);
}

int main () {
  scanf("%s", s);

  stringNx(s);
  printf("%s", s);
  return 0;
}