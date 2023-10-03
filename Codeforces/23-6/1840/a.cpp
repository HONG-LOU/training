/**
 *    author:  HONG-LOU
 *    created: 2023-06-07 13:28:32
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    s += " ";
    std::string ans = "";
    ans += s[0];
    char cnt = s[0];
    for (int i = 1; i < n; i++) {
      if (s[i] == cnt) {
        if (i < n - 1) {
          ans += s[i + 1];
          cnt = s[i + 1];
          i++;
        }
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}