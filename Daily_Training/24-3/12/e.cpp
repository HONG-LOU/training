/**
 *    author:  HONG-LOU
 *    created: 2024-03-12 20:43:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  int ans = 0;
  std::vector vis(n, std::vector<int>(m, 0));
  int d[3] = {-1, 0, 1};
  auto check = [&] (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
      return false;
    }
    return true;
  };
  std::function<void(int, int)> dfs = [&] (int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (d[i] == 0 && d[j] == 0) {
          continue;
        }
        int nx = x + d[i];
        int ny = y + d[j];
        if (check(nx, ny) && s[nx][ny] == 'W' && !vis[nx][ny]) {
          dfs(nx, ny);
        } 
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'W' && !vis[i][j]) {
        ans += 1;
        dfs(i, j);
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}