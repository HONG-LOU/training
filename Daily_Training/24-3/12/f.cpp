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
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'W' && !vis[i][j]) {
        ans += 1;
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        int d[3] = {-1, 0, 1};
        while (!q.empty()) {
          auto cnt = q.front();
          q.pop();
          for (int ii = 0; ii < 3; ii++) {
            for (int jj = 0; jj < 3; jj++) {
              if (ii == 1 && jj == 1) {
                continue;
              }
              int nx = cnt.first + d[ii];
              int ny = cnt.second + d[jj];
              if (check(nx, ny) && s[nx][ny] == 'W' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
              }
            }
          }
        }
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}