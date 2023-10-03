/**
 *    author:  HONG-LOU
 *    created: 2023-06-07 13:57:54
**/
#include <bits/stdc++.h>



auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k, q;
    std::cin >> n >> k >> q;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x <= q) {
        cnt++;
      }
    }

  }
  return 0;
}