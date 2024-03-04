/**
 *    author:  HONG-LOU
 *    created: 2023-11-29 15:28:53
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, x;
  std::cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    if (x >= m) {
      ans++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}