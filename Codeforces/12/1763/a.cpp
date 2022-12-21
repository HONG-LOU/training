/**
 *    author:  HONG-LOU
 *    created: 2022-12-20 22:22:16
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int x = -1;
    int y = 0;
    for (int i = 0; i < n; i++) {
      int a;
      std::cin >> a;
      x &= a;
      y |= a;
    }
    std::cout << y - x << "\n";
  }
  return 0;
}