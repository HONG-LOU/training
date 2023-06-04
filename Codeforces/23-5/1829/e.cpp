/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 14:21:15
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::vector s(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> s[i][j];
      }
    }
    int mx = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    std::vector vis(n, std::vector<bool>(m, false));
    auto check = [&] (int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };
    int cnt = 0;
    std::function<void(int, int)> dfs = [&] (int x, int y) {
      vis[x][y] = true;
      cnt += s[x][y];
      for (int i = 0; i < 4; i++) {
        if (check(x + dx[i], y + dy[i]) && s[x + dx[i]][y + dy[i]] != 0 && !vis[x + dx[i]][y + dy[i]]) {
          dfs(x + dx[i], y + dy[i]);
        }
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] != 0 && !vis[i][j]) {
          dfs(i, j);
          mx = std::max(cnt, mx);
          cnt = 0;
        }
      }
    }
    std::cout << mx << "\n";
  }
  return 0;
}