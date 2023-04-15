/**
 *    author:  HONG-LOU
 *    created: 2023-04-03 20:31:20
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
    int res = -1;
    for (int i = 0; i <= (1 << 8); i++) {
      auto b = a;
      int c = 0;
      for (int j = 0; j < n; j++) {
        b[j] ^= i;
        c ^= b[j];
      }
      if (c == 0) {
        res = i;
        break;
      }
    }
    std::cout << res << "\n";
  }
  return 0;
}