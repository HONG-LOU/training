/**
 *    author:  HONG-LOU
 *    created: 2023-04-16 15:17:13
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    int n = (int) s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == '_' && s[i - 1] == '_') {
        ans++;
      }
    }
    if (s[0] == '_') {
      ans++;
    }
    if (s[n - 1] == '_') {
      ans++;
    }
    if (s == "^") {
      ans = 1;
    }
    std::cout << ans << "\n";
  }
  return 0;
}