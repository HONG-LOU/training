/**
 *    author:  HONG-LOU
 *    created: 2023-04-16 15:47:14
**/
#include <bits/stdc++.h>

#define int long long

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    int n = (int) s.size();
    s += s;
    int mx = 0, cnt = 0;
    for (int i = 0; i < n * 2; i++) {
      if (s[i] == '0') {
        mx = std::max(mx, cnt);
        cnt = 0;
      }
      else {
        cnt += 1;
      }
    }
    mx = std::max(mx, cnt);
    int ans = 0;
    if (mx >= n) {
      ans = n * n;
    }
    else {
      for (int i = 1; i <= mx; i++) {
        ans = std::max(ans, i * (mx + 1 - i));
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}