/**
 *    author:  HONG-LOU
 *    created: 2023-02-07 13:35:21
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = 0;
    std::map<int, int> x, y;
    x[s[0]]++;
    for (int i = 1; i < n; i++) {
      y[s[i]]++;
    }
    ans = std::max(ans, (int) x.size() + (int) y.size());
    for (int i = 1; i < n - 1; i++) {
      x[s[i]]++;
      y[s[i]]--;
      int xx = 0, yy = 0;
      for (int j = 'a'; j <= 'z'; j++) {
        if (x[j] > 0) xx++;
        if (y[j] > 0) yy++;
      }
      ans = std::max(ans, xx + yy);
    }
    std::cout << ans << "\n";
  }
  return 0;
}