/**
 *    author:  HONG-LOU
 *    created: 2022-12-19 22:36:33
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool ok = true;
      for (int k = 0; k < m; k++) {
        if (s[i][k] != 'o' && s[j][k] != 'o') {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans++;
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}