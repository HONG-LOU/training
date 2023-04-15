/**
 *    author:  HONG-LOU
 *    created: 2023-04-03 20:54:23
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
    std::vector<std::vector<int>> c(26);
    for (int i = n - 1; i >= 0; i--) {
      c[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i <= (s[0] - 'a'); i++) {
      if (c[i].size() >= 2 && i == (s[0] - 'a')) {
        if (c[i].)
      }

    }
  }
  return 0;
}