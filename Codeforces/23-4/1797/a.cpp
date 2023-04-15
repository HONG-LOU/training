/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 11:38:37
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int ans = 4;
    if (x1 == 1 || y1 == 1 || x1 == n || y1 == m) {
      if (x1 == 1 || x1 == n) {
        ans = std::min(ans, ans - 1);
      }
      if (y1 == 1 || y1 == m) {
        ans = std::min(ans, ans - 1);
      }
    }
    int cans = 4;
    if (x2 == 1 || y2 == 1 || x2 == n || y2 == m) {
      if (x2 == 1 || x2 == n) {
        cans = std::min(cans, cans - 1);
      }
      if (y2 == 1 || y2 == m) {
        cans = std::min(cans, cans - 1);
      }
    }
    std::cout << std::min(ans, cans) << "\n";
  }
  return 0;
}