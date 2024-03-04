/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 15:35:36
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int ans = 0;
  auto plus = [&] (int x) {
    int sum = 0;
    for (int i = 1; i <= x - 1; i++) {
      sum += i;
    }
    return sum;
  };
  std::map<int, std::vector<int>> m;
  std::vector<int> cnt(26, 0);
  m[n - 1] = cnt;
  m[n - 1][s[n - 1] - 'a']++;
  for (int i = n - 2; i >= 0; i--) {
    m[i] = m[i + 1];
    m[i][s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < 26; j++) {
      if (j == (s[i] - 'a')) {
        continue;
      }
      if (m[i][j] > 1) {
        sum += plus(m[i][j]);
      }
    }
    ans += sum;
  }
  std::cout << ans;
  return 0;
}