/**
 *    author:  HONG-LOU
 *    created: 2023-01-18 14:11:08
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int w, d, h;
    std::cin >> w >> d >> h;
    int a, b, f, g;
    std::cin >> a >> b >> f >> g;
    int ans = (int) 1e9;
    ans = std::min(ans, h + a + f + std::abs(b - g));
    ans = std::min(ans, h + b + g + std::abs(a - f));
    ans = std::min(ans, h + std::abs(w - a) + std::abs(w - f) + std::abs(b - g));
    ans = std::min(ans, h + std::abs(d - b) + std::abs(d - g) + std::abs(a - f));
    std::cout << ans << "\n";
  }
  return 0;
}