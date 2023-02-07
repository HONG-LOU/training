/**
 *    author:  HONG-LOU
 *    created: 2023-02-07 13:30:31
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
    int l = 0, r = n - 1;
    int ans = n;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == '0' && s[n - i - 1] == '1') {
        ans = n - (i + 1) - (i + 1);
      }
      else if (s[i] == '1' && s[n - i - 1] == '0') {
        ans = n - (i + 1) - (i + 1);
      }
      else {
        break;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}