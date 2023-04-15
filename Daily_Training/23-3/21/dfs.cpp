/**
 *    author:  HONG-LOU
 *    created: 2023-03-21 20:41:32
**/
#include <bits/stdc++.h>

int dis[3] = {-1, 0, 1};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  auto check = [&] (int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
  };
  std::vector<std::vector<bool>> used(n, std::vector<bool>(m, false));
  std::function<void(int, int)> dfs = [&] (int x, int y) {
    if (s[x][y] == 'X') return;
    used[x][y] = true;
    if (check(x + 1, y) && !used[x + 1][y]) dfs(x + 1, y);
    if (check(x - 1, y) && !used[x - 1][y]) dfs(x - 1, y);
    if (check(x, y - 1) && !used[x][y - 1]) dfs(x, y - 1);
    if (check(x, y + 1) && !used[x][y + 1]) dfs(x, y + 1);
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
        dfs(i, j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') std::cout << 'X';
      else if (!used[i][j]) std::cout << 'X';
      else std::cout << 'O';
    }
    std::cout << std::endl;
  }
  return 0;
}