#include <stdio.h>
#include <string.h>


int main () {
  char s[] = "\a\\a\\\a\\\\n";
  int len = strlen(s);
  printf("%d", len);
  return 0;
}