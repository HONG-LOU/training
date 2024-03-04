#include <stdio.h>

int search(int list[], int n, int x) {
  int i;
  for (i = 0; i < n; i++) {
    if (list[i] == x) {
      return i;
    }
  }
  return -1;
}

int main () {
  int n;
  scanf("%d", &n);
  int list[n];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &list[i]);
  }
  int x;
  scanf("%d", &x);
  int index = search(list, n, x);
  if (index == -1) {
    printf("Not found");
  }
  else {
    printf("index = %d", index);
  }
  return 0;
}