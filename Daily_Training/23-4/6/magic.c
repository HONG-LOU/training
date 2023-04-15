/**
 *    author:  HONG-LOU
 *    created: 2023-04-06 16:49:47
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[101][101] = {0};

// ROW & 1

void F(int ROW) {
  if (ROW % 2 == 0) {
    printf("ERROR NUMBER!\n");
    return;
  }
  memset(arr, 0, sizeof arr);
  arr[0][ROW / 2] = 1;
  int currow = 0;
  int curcol = ROW / 2;

  int i = 0;
  int j = 0;

  for (int i = 2; i <= ROW * ROW; i++) {
    if (arr[(currow + ROW - 1) % ROW][(curcol + 1) % ROW] != 0) {
      currow = (currow + 1 + ROW) % ROW;
    }
    else {
      currow = (currow - 1 + ROW) % ROW;
      curcol = (curcol + 1 + ROW) % ROW;
    }
    arr[currow][curcol] = i;
  }
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < ROW; j++) {
      printf("%-5d", arr[i][j]);
    }
    printf("\n");
  }
}

// N % 2 == 0

void S(int N) {
  memset(arr, 0, sizeof arr);
  if (N % 4 != 0) {
    printf("ERROR NUMBER!\n");
    return;
  }
  int i;
  int j;
  int lvalue = 1;
  int rvalue = N * N;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i % 4 == j % 4 || (i + j) % 4 == 3) {
        arr[i][j] = rvalue;
      }
      else {
        arr[i][j] = lvalue;
      }
      lvalue++;
      rvalue--;
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%-5d", arr[i][j]);
    }
    printf("\n");
  }
}

// MAX = 4x + 2 (x = 1, 2, 3....)

void T(int MAX) {
  int i = 0;
  int j = 0;
  if ((MAX - 2) % 4 != 0) {
    printf("ERROR NUMBER!\n");
    return;
  } 
  memset(arr, 0, sizeof arr);

  arr[0][MAX / 4] = 1;
  int currow = 0;
  int curcol = MAX / 4;
  for (i = 2; i <= MAX * MAX / 4; i++) {
    if (arr[(currow - 1 + MAX / 2) % (MAX / 2)][(curcol + 1) % (MAX / 2)] != 0) {
      currow = (currow + 1) % (MAX / 2);
    }
    else {
      currow = (currow - 1 + MAX / 2) % (MAX / 2);
      curcol = (curcol + 1) % (MAX / 2);
    }
    arr[currow][curcol] = i;
  }
  arr[MAX / 2][MAX * 3 / 4] = MAX * MAX / 4 + 1;
  currow = MAX / 2;
  curcol = MAX * 3 / 4;
  for (i = MAX * MAX / 4 + 2; i <= MAX * MAX / 2; i++) {
    if (arr[(currow - 1 + MAX / 2) % (MAX / 2) + MAX / 2][(curcol + 1 + MAX / 2) % (MAX / 2) + MAX / 2] != 0) {
      currow = (currow + 1) % (MAX / 2) + MAX / 2;
    }
    else {
      currow = (currow - 1 + MAX / 2) % (MAX / 2) + MAX / 2;
      curcol = (curcol + 1) % (MAX / 2) + MAX / 2;
    }
    arr[currow][curcol] = i;
  }
  arr[0][MAX * 3 / 4] = MAX * MAX / 2 + 1;
  currow = 0;
  curcol = MAX * 3 / 4;
  for (i = MAX * MAX / 2 + 2; i <= MAX * MAX * 3 / 4; i++) {
    if (arr[(currow - 1 + MAX / 2) % (MAX / 2)][(curcol + 1 + MAX / 2) % (MAX / 2) + MAX / 2] != 0) {
      currow = (currow + 1) % (MAX / 2);
    }
    else {
      currow = (currow - 1 + MAX / 2) % (MAX / 2);
      curcol = (curcol + 1) % (MAX / 2) + MAX / 2;
    }
    arr[currow][curcol] = i;
  }
  arr[MAX / 2][MAX / 4] = MAX * MAX / 4 * 3 + 1;
  currow = MAX / 2;
  curcol = MAX / 4;
  for (i = MAX * MAX / 4 * 3 + 2; i <= MAX * MAX; i++) {
    if (arr[(currow - 1 + MAX / 2) % (MAX / 2) + MAX / 2][(curcol + 1 + MAX / 2) % (MAX / 2)] != 0) {
      currow = (currow + 1) % (MAX / 2) + MAX / 2;
    }
    else {
      currow = (currow - 1) % (MAX / 2) + MAX / 2;
      curcol = (curcol + 1) % (MAX / 2);
    }
    arr[currow][curcol] = i;
  }

  int k = MAX / 4;
  int tmp = 0;
  for (i = 0; i < MAX / 2; i++) {
    for (j = 0; j < MAX; j++) {
      if (i == k && j >= k && j <= 2 * k - 1) {
        tmp = arr[i][j];
        arr[i][j] = arr[i + MAX / 2][j];
        arr[i + MAX / 2][j] = tmp;
      }
      if (i != k && j >= 0 && j < k) {
        tmp = arr[i][j];
        arr[i][j] = arr[i + MAX / 2][j];
        arr[i + MAX / 2][j] = tmp;
      }
      if (j >= MAX / 2 + MAX / 4 - k + 2 && j <= MAX / 2 + MAX / 4) {
        tmp = arr[i][j];
        arr[i][j] = arr[i + MAX / 2][j];
        arr[i + MAX / 2][j] = tmp;
      }
    }
  }

  for (i = 0; i < MAX; i++) {
    for (j = 0; j < MAX; j++) {
      printf("%-5d", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n;
  scanf("%d", &n);
  F(n);
  scanf("%d", &n);
  S(n);
  scanf("%d", &n);
  T(n);
  return 0;
}