/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 12:21:52
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    auto ask = [&] (int x, int y) {
      std::cout << '?' << ' ' << x << ' ' << y << std::endl;
      int d;
      std::cin >> d;
      return d;
    };
    int n, m;
    std::cin >> n >> m;
    int a = ask(1, 1);
    int b = ask(n, m);
    int x, y;
    if (a + b == n - 1) {
      x = 1 + a;
      y = 1 + ask(x, 1);
    } else if (a + b == m - 1) {
      y = 1 + a;
      x = 1 + ask(1, y);
    } else {
      if (1 + a <= n && m - b >= 1 && ask(1 + a, m - b) == 0) {
        x = 1 + a;
        y = m - b;
      } else {
        x = n - b;
        y = 1 + a;
      }
    }
    std::cout << "! " << x << " " << y << std::endl;
  }
  return 0;
}