#include <stdio.h>

int a[1010101];

// a[4] = 13 ==> 4 --> 13

int main () {
  int n;
  scanf("%d",&n);
  int i;
  int mx = 0;
  for (i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x + 101010]++;
    if (a[x + 101010] > mx) {
      mx = a[x + 101010];
    }
  }
  for (i = 0; i < 1010101; i++) {
    if (a[i] == mx) {
      printf("%d %d\n", i - 101010, mx);
    }
  }
  return 0; 
}
