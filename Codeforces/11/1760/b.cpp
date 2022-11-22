/**
 *    author:  HONG-LOU
 *    created: 2022-11-22 11:16:59
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = std::max(ans, s[i] - 'a' + 1);
    }
    std::cout << ans << "\n";
  }  
  return 0;
}