/**
 *    author:  HONG-LOU
 *    created: 2023-01-03 14:02:25
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    int l = 1, r = n;
    while (l <= r) {
      std::cout << r-- << ' ';
      if (l > r) {
        break;
      }
      std::cout << l++ << ' ';
    }
    std::cout << "\n";
  }  
  return 0;
}