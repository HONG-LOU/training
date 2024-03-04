/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 15:35:36
**/
#include <bits/stdc++.h>

#define int long long

int m[101010][26] = {0};

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int ans = 0;
  auto plus = [&] (int x) {
    return x + (x * (x - 1) / 2);
  };
  m[n - 1][s[n - 1] - 'a']++;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
        m[i][j] = m[i + 1][j];
    }
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