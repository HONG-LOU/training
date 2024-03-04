#include <stdio.h>

void display(char board[3][3]) {
  int i, j;
  printf("\f");
  for (int i = 0; i < 3; i++) {
    printf("-------\n|");
    for (j = 0; j < 3; j++) {
      printf("%c|", board[i][j]);
    }
    printf("\n");
  }
  printf("-------\n\n");
}