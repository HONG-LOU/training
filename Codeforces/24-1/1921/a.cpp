/**
 *    author:  HONG-LOU
 *    created: 2024-01-15 22:37:10
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::vector<int> a(4), b(4);
    for (int i = 0; i < 4; i++) {
      std::cin >> a[i] >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::cout << (a[3] - a[0]) * (b[3] - b[0]) << "\n";
  }
  return 0;
}