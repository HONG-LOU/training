#include <stdio.h>

int isPrime(int x) {
  int i;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int check[1001] = {0};

void init() {
  int i, j;
  for (i = 2; i * i <= 1000; i++) {
    for (j = 2; i * j <= 1000; j++) {
      check[i * j] = 1;
    }
  }
}

int main () {
  int i;
  for (i = 950; i <= 999; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
  init();
  for (i = 950; i <= 999; i++) {
    if (!check[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}