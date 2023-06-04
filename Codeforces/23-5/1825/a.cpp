/**
 *    author:  HONG-LOU
 *    created: 2023-05-09 12:43:59
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    int len = (int) s.size();
    std::string cnt;
    auto check = [&] (std::string ss) {
      return ss == std::string(ss.rbegin(), ss.rend());
    };
    int ans = -1;
    for (int i = 0; i < len; i++) {
      cnt = "";
      for (int j = i; j < len; j++) {
        cnt += s[j];
        if (!check(cnt)) {
          ans = std::max(ans, j - i + 1);
        }
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}