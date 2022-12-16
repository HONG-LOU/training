/**
 *    author:  HONG-LOU
 *    created: 2022-12-16 16:19:17
**/
#include <bits/stdc++.h>

const int mod = 998244353;

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0;
    char z = 'x';
    int wt = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] != z) {
        z = s[i];
        wt = 1;
      }
      else {
        wt = 2 * wt % mod;
      }
      ans = (ans + wt) % mod;
    }
    std::cout << ans << "\n";
  }  
  return 0;
}