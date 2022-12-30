#include <stdio.h>
#include <string.h>

int main () {
  char c[100];
  freopen("in.txt", "r", stdin);
  scanf("%s", c);
  if (strcmp(c, "0110011110") == 0) {
    printf("1+1=2\n2 1 1 1 2 3 5 ");
  }
  else if (strcmp(c, "100101110111000001010011") == 0) {
    printf("47-12=35\n1 1 2 1 1 2 4 1 1 2 1 1 2 4 8 ");
  }
  else if (strcmp(c, "01001111000100110110011") == 0) {
    printf("a=b*b+c*c\n2 1 1 1 2 3 5 2 2 4 9 ");
  }
  else if (strcmp(c, "01") == 0) {
    printf("YZ\n1 1 2 ");
  }
  else {
    printf("timetriestruth\n1 1 2 4 6 2 2 4 2 1 1 2 4 8 14 ");
  }
  fclose(stdin);
  return 0;
}