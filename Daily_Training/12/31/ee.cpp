/**
 *    author:  HONG-LOU
 *    created: 2022-12-31 11:13:41
**/
#include <bits/stdc++.h>

std::map<int, long long> x;

const int mod = 99999;

long long ask (int n) {
  if (x[n]) {
    return x[n];
  }
  else {
    return x[n] = (((ask(n - 1) * 5) % mod) + ((ask(n - 2) * 8) % mod)) % mod;
  }
}

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  x[1] = 5;
  x[2] = 33;

  int tt;
  std::cin >> tt;
  while (tt--) {
    int l;
    std::cin >> l;
    std::cout << ask(l) << "\n";
  }
  return 0;
}