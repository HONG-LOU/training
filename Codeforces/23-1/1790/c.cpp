/**
 *    author:  HONG-LOU
 *    created: 2023-01-28 15:39:53
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n - 1));
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        std::cin >> a[i][j];
        if (j == 0) {
          c[a[i][j] - 1]++;
        }
      }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i - 1] == n - 1) {
        f = i;
      }
    }
    std::cout << f << ' ';
    for (int i = 0; i < n; i++) {
      if (a[i][0] != f) {
        for (int j = 0; j < n - 1; j++) {
          std::cout << a[i][j] << ' ';
        }
      }
    }
    std::cout << "\n";
  }
  return 0;
}