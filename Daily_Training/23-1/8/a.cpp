/**
 *    author:  HONG-LOU
 *    created: 2023-01-08 14:14:25
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string t;
  std::cin >> t;
  auto s = t;
  std::reverse(s.begin() + n, s.end());
  std::vector<int> f(2 * n + 1);
  for (int i = 1, j = 0; i < 2 * n; i++) {
    while (j && s[i] != s[j]) j = f[j];
    j += (s[i] == s[j]);
    f[i + 1] = j;
  }
  std::vector<int> ok(n + 1);
  for (int i = 2 * n; ; i = f[i]) {
    if (i <= n) {
      ok[i]++;
    }
    if (!i) {
      break;
    }
  }
  std::reverse(s.begin(), s.begin() + n);
  std::reverse(s.begin() + n, s.end());
  for (int i = 1, j = 0; i < 2 * n; i++) {
    while (j && s[i] != s[j]) j = f[j];
    j += (s[i] == s[j]);
    f[i + 1] = j;
  }
  for (int i = 2 * n; ; i = f[i]) {
    if (i <= n) {
      ok[n - i]++;
    }
    if (!i) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (ok[i] == 2) {
      std::cout << t.substr(0, i) + t.substr(n + i) << "\n";
      std::cout << i << "\n";
      return 0;
    }
  }
  std::cout << -1 << "\n";
  return 0;
}