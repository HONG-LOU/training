/**
 *    author:  HONG-LOU
 *    created: 2023-04-29 21:11:04
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::string> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  bool ok = false;
  for (int p = 0; p < n; p++) {
    for (int q = 0; q < m; q++) {
      auto c = a;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          c[i][j] = a[(i + p) % n][(j + q) % m];
        }
      }
      if (c == b) {
        ok = true;
      }
    }
  }
  std::cout << (ok ? "Yes\n" : "No\n");
  return 0;
}