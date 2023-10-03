/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 17:02:28
**/
#include <bits/stdc++.h>

#define int long long

const int mod = (int) 1e9 + 7, N = (int) 1e5 + 10;

long long fac[N], infac[N];

int quick_pow(int a, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * a % p;
    }
    a = a * a % p;
    k >>= 1;
  }
  return res;
}

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  fac[0] = infac[0] = 1;
  for (int i = 1; i <= (int) 1e5; i++) {
    fac[i] = fac[i - 1] * i % mod;
    infac[i] = infac[i - 1] * quick_pow(i, mod - 2, mod) % mod;
  }
  std::cin >> n;
  while (n--) {
    int x, y;
    std::cin >> x >> y;
    std::cout << fac[x] * infac[y] % mod * infac[x - y] % mod << "\n";
  }
  return 0;
}