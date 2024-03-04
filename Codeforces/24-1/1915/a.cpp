/**
 *    author:  HONG-LOU
 *    created: 2024-01-17 17:07:58
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b, c, x = 0;
    std::cin >> a >> b >> c;
    x ^= a ^= b ^= c;
    std::cout << x << "\n";
  }
  return 0;
}