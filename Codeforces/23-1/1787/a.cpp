/**
 *    author:  HONG-LOU
 *    created: 2023-01-31 16:06:34
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    if (n & 1) {
      std::cout << -1 << "\n";
    }
    else {
      std::cout << 1 << ' ' << n / 2 << "\n";
    }
  }
  return 0;
}