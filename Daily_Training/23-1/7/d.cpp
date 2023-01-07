/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 21:48:11
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    long long n;
    std::cin >> n;
    for (long long i = 2; i * i * i <= n; i++) {
      if (n % (i * i) == 0) {
        std::cout << i << ' ' << n / (i * i) << "\n";
        break;
      }
      else if (n % i == 0) {
        long long v = std::sqrt(n / i) + 0.1;
        if (i * v * v == n) {
          std::cout << v << ' ' << i << "\n";
          break;
        }
      }
    }
  }
  return 0;
}