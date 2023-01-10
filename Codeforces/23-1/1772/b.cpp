/**
 *    author:  HONG-LOU
 *    created: 2023-01-10 13:44:34
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  auto c = [&] (std::vector<std::vector<int>> a) {
    std::swap(a[0][0], a[0][1]);
    std::swap(a[0][0], a[1][0]);
    std::swap(a[1][0], a[1][1]);
    return a;
  }; 
  while (tt--) {
    std::vector<std::vector<int>> a(2, std::vector<int>(2));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        std::cin >> a[i][j];
      }
    }
    bool ok = false;
    for (int i = 0; i < 4; i++) {
      if (a[0][0] < a[0][1] && a[1][0] < a[1][1] && a[0][0] < a[1][0] && a[0][1] < a[1][1]) {
        ok = true;
        break;
      }
      a = c(a);
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }  
  return 0;
}