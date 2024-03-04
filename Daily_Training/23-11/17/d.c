#include <stdio.h>

int gcd1(int a, int b) {
  int i;
  int ans = 1;
  for (i = (a > b ? b : a); i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      ans = i;
      break;
    }
  }
  return ans;
}

int gcd2(int a, int b) {
  while(b ^= a ^= b ^= a %= b);
  return a;
}

int gcd3(int a, int b) {
  return b ? gcd3(b, a % b) : a;
}

int main () {
  int a, b;
  scanf("%d/%d", &a, &b);
  int gc1 = gcd1(a, b);
  int gc2 = gcd2(a, b);
  int gc3 = gcd3(a, b);
  a /= gc1, b/= gc1;
  printf("%d %d %d\n", gc1, gc2, gc3);
  printf("%d/%d\n", a, b);
  return 0;
}