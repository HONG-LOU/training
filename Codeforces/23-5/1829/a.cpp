/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 14:00:33
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    std::string b = "codeforces";
    int ans = 0;
    for (int i = 0; i < 10; i++) {
      ans += !(b[i] == s[i]);
    }
    std::cout << ans << "\n";
  }
  return 0;
}