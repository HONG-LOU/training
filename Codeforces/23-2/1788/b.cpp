/**
 *    author:  HONG-LOU
 *    created: 2023-02-12 11:39:57
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  auto ask = [&] (int x) {
    int ans = 0;
    while (x) {
      ans += x % 10;
      x /= 10;
    }
    return ans;
  };
  while (tt--) {
    int n;
    std::cin >> n;
    int x = 0, y = 0, s = 0;
    for (auto &c : std::to_string(n)) {
      int a = c - '0';
      if (a & 1) {
        x = x * 10 + (a + s) / 2;
        y = y * 10 + (a + !s) / 2;
        s ^= 1;
      }
      else {
        x = x * 10 + a / 2;
        y = y * 10 + a / 2;
      }
    }
    std::cout << x << ' ' << y << "\n";
  }
  return 0;
}