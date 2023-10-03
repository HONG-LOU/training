/**
 *    author:  HONG-LOU
 *    created: 2023-07-27 09:46:52
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
    std::vector<std::vector<int>> c(26);
    for (int i = 0; i < len; i++) {
      c[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      int sz = (int) c[i].size();
      std::sort(c[i].begin(), c[i].end());
      if (sz & 1) {
        ans++;
        sz--;
      }
      // if (sz) {
      //   for (int j = 0; j < sz; j++) {
      //     std::cout << c[i][j] << " \n"[j == sz - 1];
      //   }
      // }
      for (int j = 0; j < sz; j += 2) {
        if (c[i][j + 1] - c[i][j] > 1) ans += 1;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}