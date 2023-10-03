/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 16:47:49
**/
#include <bits/stdc++.h>

int c[3030][3030] = {0};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  c[1][1] = 1;
  const int mod = (int) 1e9 + 7;
  for (int i = 2; i <= 2000; i++) {
    c[i][1] = i;
    for (int j = 2; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  int tt;
  std::cin >> tt;
  while (tt--) {
    int x, y;
    std::cin >> x >> y;
    std::cout << c[x][y] << "\n";
  }
  return 0;
}