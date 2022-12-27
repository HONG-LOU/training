/**
 *    author:  HONG-LOU
 *    created: 2022-12-27 23:41:29
**/
#include <bits/stdc++.h>

const int mod = (int) 1e9 + 7;

long long C (long long n) {
  long long x = n;
  n *= (x + 1);
  x = x * 4 - 1;
  n *= x;
  n /= 6;
  n *= 2022;
  return n;
}

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cout << mod << "\n";
  std::cin >> tt;
  while (tt--) {
    long long n;
    std::cin >> n;
    std::cout << C(n) << "\n";
  }
  return 0;
}