/**
 *    author:  HONG-LOU
 *    created: 2024-03-28 19:34:58
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector g(n, std::vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> g[i][j];
    }
  }
  std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  auto check = [&] (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  int ans = 0;
  int cnt = 0;
  std::function<void(int, int)> dfs = [&] (int x, int y) {
    cnt++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (check(nx, ny) && vis[nx][ny] == 0 && g[nx][ny] < g[x][y]) {
        dfs(nx, ny);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::vector v(n, std::vector<int>(m, 0));
      vis = v;
      cnt = 0;
      dfs(i, j);
      ans = std::max(ans, cnt);
    }
  }
  std::cout << ans << "\n";
  return 0;
}