/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 15:59:03
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << n % m << ' ' << m << "\n";

    int cnt = n % m;
    if (cnt & 1) {
      std::cout << "0\n";
    }
    else {
      if (m & 1) {
        std::cout << 1 << "\n";
      }
      else {
        std::cout << m << "\n";
      }
    }
  }
  // 18 12 11 5 4 3 2 1
  return 0;
}