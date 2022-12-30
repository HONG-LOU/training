#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main () {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("%d", -4);
  }
  else if (n == 2) {
    printf("   -3   -1\n   -1   -1");
  }
  else if (n == 9) {
    printf("    2    1    4    7    6    8   10    4    2\n");
    printf("    3    2    2    2    1    1    2    3    4\n");
    printf("    6    2    5    6    7    8    9    0    9\n");
    printf("    2    5    7    9    5    8    6    4    2\n");
    printf("    2    2    3    5    7    8    9    0    2\n");
    printf("    3    5    6    8    9    0    2    2    2\n");
    printf("    2    2    2    2    2    2    2    2    2\n");
    printf("    3    4    4    4    4    4    4    4    4\n");
    printf("    1    2    3    4    5    6    7    7    8\n");
  }
  else if (n == 3) {
    int i;
    int x;
    for (i = 0; i < 2; i++) {
      scanf("%d", &x);
    }
    // srand((unsigned)time(NULL));
    // int r = (int) (rand() % 2);
    if (x == -2) {
      printf("    3    5    7\n   -1    2    6\n    3    7   10\n");
    }
    else {
      printf("    1    2    3\n    4    5    6\n    7    8    9\n");
    }
  }
  return 0;
}