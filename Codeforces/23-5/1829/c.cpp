/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 14:04:48
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  const int mx = (int) 1e9;
  while (tt--) {
    int n;
    std::cin >> n;
    int x = mx, y = mx, z = mx;
    for (int i = 0; i < n; i++) {
      int cnt;
      std::cin >> cnt;
      std::string s;
      std::cin >> s;
      if (s == "11") {
        x = std::min(x, cnt);
      }
      else if (s == "01") {
        y = std::min(y, cnt);
      }
      else if (s == "10") {
        z = std::min(z, cnt);
      }
    }
    if (x != mx && y != mx && z != mx) {
      std::cout << std::min(x, y + z) << "\n";
    }
    else if (x != mx) {
      std::cout << x << "\n";
    }
    else if (y != mx && z != mx) {
      std::cout << y + z << "\n";
    }
    else {
      std::cout << -1 << "\n";
    }
  }
  return 0;
}