/**
 *    author:  HONG-LOU
 *    created: 2022-12-16 16:57:30
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  auto ask = [&] (int x, int y) {
    std::cout << "? " << x + 1 << ' ' << y + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
  };
  while (tt--) {
    int n;
    std::cin >> n;
    int x = 0, y = 1;
    int g = ask(x, y);
    for (int i = 2; i < n; i++) {
      int gx = ask(i, x);
      int gy = ask(i, y);
      if (gx >= std::max(gy, g)) {
        y = i;
        g = gx;
      }
      else if (gy >= std::max(gx, g)) {
        x = i;
        g = gy;
      }
    }
    std::cout << "! " << x + 1 << ' ' << y + 1 << std::endl;
    int res;
    std::cin >> res;
  }  
  return 0;
}