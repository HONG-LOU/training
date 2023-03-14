/**
 *    author:  HONG-LOU
 *    created: 2023-02-17 12:48:33
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    bool lo = false, ro = false;
    for (int i = 0; i < n; i++) {
      int l, r;
      std::cin >> l >> r;
      if (l == k) {
        lo = true;
      }
      if (r == k) {
        ro = true;
      }
    }
    std::cout << (ro && lo ? "YES\n" : "NO\n");
  }
  return 0;
}