/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 11:54:22
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    std::vector s(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> s[i][j];
      }
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] != s[n - i - 1][n - j - 1]) {
          sum++;
        }
      }
    }
    if (sum / 2 <= k) {
      if (n & 1) {
        std::cout << "YES\n";
      }
      else if ((k - sum / 2) & 1) {
        std::cout << "NO\n";
      }
      else {
        std::cout << "YES\n";
      }
    }
    else {
      std::cout << "NO\n";
    }
  }
  return 0;
}