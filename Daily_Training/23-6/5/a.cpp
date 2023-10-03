/**
 *    author:  HONG-LOU
 *    created: 2023-06-05 19:38:07
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    int cnt = 1;
    std::vector a(n, std::vector<int>(m));
    for (int i = 1; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        a[i][j] = cnt++;
      }
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        a[i][j] = cnt++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << a[i][j] << " \n"[j == m - 1];
      }
    }
  }
  return 0;
}