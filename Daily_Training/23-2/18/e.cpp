/**
 *    author:  HONG-LOU
 *    created: 2023-02-18 19:57:24
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
    int o = 0;
    for (int i = 0; i < n; i++) {
      o += (s[i] == '1');
    }
    if (o & 1) {
      std::cout << -1 << "\n";
    }
    else if (o == 0) {
      std::cout << 0 << "\n";
    }
    else {
      int l = 0, r = n - 1;
      while (s[l] != '1') l++;
      while (s[r] != '1') r--;
      int ans = o / 2;
      if (l + 1 >= r) {
        ans++;
      }
      std::cout << ans << "\n";
    }
  }
  return 0;
}