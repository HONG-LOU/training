/**
 *    author:  HONG-LOU
 *    created: 2023-02-12 11:31:07
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
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (a[i] == 2) {
        r++;
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == 2) {
        l++, r--;
      }
      if (l == r) {
        ok = true;
        std::cout << i + 1 << "\n";
        break;
      }
    }
    if (!ok) {
      std::cout << -1 << "\n";
    }
  }
  return 0;
}