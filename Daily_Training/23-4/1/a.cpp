/**
 *    author:  HONG-LOU
 *    created: 2023-04-01 15:05:34
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b;
    std::cin >> a >> b;
    int mmx = 0, ans = 0;
    for (int i = a; i <= b && i <= a + 110; i++) {
      int cnt = i;
      int mx = 100;
      int my = 0;
      while (cnt) {
        mx = std::min(cnt % 10, mx);
        my = std::max(cnt % 10, my);
        cnt /= 10;
      }
      if (my - mx > mmx) {
        mmx = my - mx;
        ans = i;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}