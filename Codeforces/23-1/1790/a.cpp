/**
 *    author:  HONG-LOU
 *    created: 2023-01-28 14:45:35
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string cnt;
    std::cin >> cnt;
    int ans = 0;
    for (int i = 0; i < (int) cnt.size(); i++) {
      if (s[i] == cnt[i]) {
        ans++;
      }
      else {
        break;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}