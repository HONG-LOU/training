/**
 *    author:  HONG-LOU
 *    created: 2024-02-14 19:58:42
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[0]) {
        break;
      }
      l++;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] != a[n - 1]) {
        break;
      }
      r++;
    }
    if (a[0] == a[n - 1]) {
      l += r + 1;
    }
    std::cout << std::max(0, std::min({n - 1, n - l - 1, n - r - 1})) << "\n";
  }
  return 0;
}