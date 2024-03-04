#include <stdio.h>

int a[110], b[110];

int c[1010];

int ans[1010];

int main () {
  
  int n, m;
  scanf("%d", &n);

  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  int j;

  int num = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        c[num] = a[i];
        num++;
        break;
      }
    }
  }

  for (i = 0; i < num; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");

  for (i = 0; i < num; i++) {
    int isexited = 0;
    for (j = 0; j < i; j++) {
      if (c[j] == c[i]) {
        isexited = 1;
        break;
      }
    }
    if (!isexited) {
      printf("%d ", a[i]);
    }
  }

  return 0;
}