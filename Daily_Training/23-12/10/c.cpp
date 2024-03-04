/**
 *    author:  HONG-LOU
 *    created: 2023-12-10 14:00:36
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
    std::vector<int> c(26, 0);
    for (int i = 0; i < n; i++){
      c[s[i] - 'a']++;
    }
    int mx = *std::max_element(c.begin(), c.end());
    int ans = std::max(n & 1 ? 1 : 0, mx - (n - mx));
    std::cout << ans << "\n";
  }
  return 0;
}