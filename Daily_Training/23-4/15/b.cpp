/**
 *    author:  HONG-LOU
 *    created: 2023-04-15 20:11:12
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector a(n, std::vector<int>(n));
  std::vector b(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> b[i][j];
    }
  }
  auto print = [&] (std::vector<std::vector<int>> x) {
    for (auto cnt : x) {
      for (auto in : cnt) {
        std::cout << in << ' ';
      }
      std::cout << "\n";
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1 && b[i][j] == 1) {
        std::swap(a[i][j], a[n - j - 1][i]);
      }
    }
  }
  print(a);
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1 && b[i][j] == 0) {
        ok = false;
        break;
      }
    }
  }
  std::cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}