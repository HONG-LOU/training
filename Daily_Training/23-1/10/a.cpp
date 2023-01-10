/**
 *    author:  HONG-LOU
 *    created: 2023-01-10 15:47:44
**/
#include <bits/stdc++.h>

int a[1010][1010] = {0};

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cin >> a[i][j];
      a[i][j] = std::max(a[i][j] + a[i - 1][j], a[i][j] + a[i - 1][j - 1]);
    }
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = std::max(mx, a[n][i]);
  }
  std::cout << mx << "\n";
  return 0;
}