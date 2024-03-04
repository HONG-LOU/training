/**
 *    author:  HONG-LOU
 *    created: 2023-11-17 15:09:47
**/
#include <stdio.h>
#include "display.h"
#include "check.h"

char board[3][3];

void change(int x, int y, char c) {
  board[x - 1][y - 1] = c;
}

void clear() {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

int gaming(int r) {
  int i;
  clear();
  int checkans = 0;
  for (i = 0; i < 9; i++) {
    printf("(Game %d) -> Round %d(%c) ==> ", r, i + 1, i & 1 ? 'O' : 'X');
    printf("Please input location : ");
    int x, y;
    scanf("%d %d", &x, &y);
    if (board[x - 1][y - 1] != ' ') {
      printf("\nError Input!\n\n");
      i--;
      continue;
    }
    char c = (i & 1 ? 'O' : 'X');
    change(x, y, c);
    display(board);
    checkans = check(board);
    if (checkans) {
      break;
    }
  }
  printf("Game Over!     ");
  if (checkans == 1) {
    printf("X win!!!\n\n");
  }
  else if (checkans == 2) {
    printf("O win!!!\n\n");
  }
  else {
    printf("No one Win...\n\n");
  }
  printf("Continue Gaming(Y/N)? ");
  char c;
  getchar();
  scanf("%c", &c);
  printf("\n");
  return c == 'Y';
}

int main() {
  int i, j;
  clear();
  int r = 1;
  while (1) {
    int co = gaming(r++);
    if (!co) {
      break;
    }
  }
  printf("Thanks\n");
  return 0;
}