/**
 *    author:  HONG-LOU
 *    created: 2023-01-10 14:47:29
**/
#include <bits/stdc++.h>

auto main() -> int {
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
    int l = 0, r = (int) 1e9;
    for (int i = 1; i < n; i++) {
      int L = 0, R = (int) 1e9;
      if (a[i] > a[i - 1]) {
        R = (a[i] + a[i - 1]) / 2;
      }
      else if (a[i] < a[i - 1]) {
        L = (a[i] + a[i - 1] + 1) / 2;
      }
      l = std::max(L, l);
      r = std::min(R, r);
    }
    if (l > r) {
      std::cout << -1 << "\n";
    }
    else {
      std::cout << l << "\n";
    }
  }
  return 0;
}