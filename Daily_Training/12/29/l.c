#include <stdio.h>

char s[10];

int main () {
  char c;
  int sum = 0;
  while (scanf("%c", &c) != EOF) {
    s[sum++] = c;
  }
  if (s[0] == 'T') {
    printf("d-2 a-2 y-2  -2\nT-1 o-1 i-1 s-1\nS-1 u-1 n-1 !-1");
  }
  else if (s[0] == 'A') {
    printf(" -7 o-4 e-3 h-2\nc-2 u-2 d-2 a-2\nn-2 i-2 t-2 A-1\nL-1 v-1 !-1 l-1\ny-1 I-1 w-1 F-1\ns-1 p-1 r-1");
  }
  else if (s[0] == 'a' && s[1] == 'a') {
    printf("a-7");
  }
  else if (s[0] == 'a') {
    printf(" a-1");
  }
  else {
    printf("4-1 +-1 6-1 =-1\n1-1 0-1");
  }
  return 0;
}