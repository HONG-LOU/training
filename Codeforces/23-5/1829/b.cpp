/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 14:02:25
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x == 0) {
        cnt += 1;
        mx = std::max(mx, cnt);
      }
      else {
        cnt = 0;
      }
    }
    std::cout << mx << "\n";
  }
  return 0;
}