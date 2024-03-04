int samecheck(char a, char b, char c) {
  if (a == b && b == c && a == c && a != ' ') {
    return 1;
  }
  else {
    return 0;
  }
}

int check(char board[3][3]) {
  // 0 no one win 
  // 1 X win
  // 2 O win
  int i;
  for (i = 0; i < 3; i++) {
    if (samecheck(board[i][0], board[i][1], board[i][2])) {
      return (board[i][0] == 'X' ? 1 : 2);
    }
  }
  for (i = 0; i < 3; i++) {
    if (samecheck(board[0][i], board[1][i], board[2][i])) {
      return (board[0][i] == 'X' ? 1 : 2);
    }
  }
  if (samecheck(board[0][0], board[1][1], board[2][2])) {
    return (board[0][0] == 'X' ? 1 : 2);
  }
  if (samecheck(board[2][0], board[1][1], board[0][2])) {
    return (board[2][0] == 'X' ? 1 : 2);
  }
  return 0;
}

