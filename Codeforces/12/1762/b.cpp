/**
 *    author:  HONG-LOU
 *    created: 2022-12-16 16:08:03
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::cout << n << "\n";
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      int p = 1 << (std::__lg(a[i]) + 1);
      std::cout << i + 1 << ' ' << p - a[i] << "\n";
    }
  }
  return 0;
}