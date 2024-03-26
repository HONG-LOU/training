/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 18:24:43
**/
#include <bits/stdc++.h>

int g[15][15] = {0};

int n;

int flag = 1;

void check(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n) {
    return;
  }
  if (g[x][y]) {
    flag = 0;
  }

}

void dfs(int deep) {
  if (deep == n + 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        std::cout << (g[i][j] == 1 ? 'Q' : '.');
      }
      std::cout << "\n";
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (g[deep][i] == 0) {
      flag = 1;
      check(deep, i);
      if (flag == 1) {
        std::cout << deep << ' ' << i << "\n";
        g[deep][i] = 1;
        dfs(deep + 1);
        g[deep][i] = 0;
      }
    }
  }
}

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> n;
  dfs(1);
  return 0;
}