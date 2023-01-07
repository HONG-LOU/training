/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 20:24:21
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x & 1) {
        ans++;
      }
    }
    std::cout << ans << "\n";
  }  
  return 0;
}