#include <stdio.h>
#include <string.h>

int main () {
  char a[101010];
  char b[101010];
  scanf("%s %s", a, b);
  int c[200] = {0};
  for (int i = 0; i < strlen(a); i++) {
    c[(int) a[i]]++;
  }
  for (int i = 0; i < strlen(b); i++) {
    c[(int) b[i]]++;
  }
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < c[i]; j++) {
      printf("%c", (char) i);
    }
  }
  return 0;
}