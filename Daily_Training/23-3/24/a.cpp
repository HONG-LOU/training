/**
 *    author:  HONG-LOU
 *    created: 2023-03-24 10:36:23
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        std::cout << '.';
      }
      else {
        std::cout << (char) (a[i][j] + 'A' - 1);
      }
    }
    std::cout << std::endl;
  }
  return 0;
}