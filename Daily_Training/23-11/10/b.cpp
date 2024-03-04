/**
 *    author:  HONG-LOU
 *    created: 2023-11-10 16:52:18
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  int ans = 0;
  std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
  int d[4] = {-1, 0, 1};
  std::function<void(int, int)> ask = [&] (int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int nx = x + d[i];
        int ny = y + d[j];
        auto check = [&] () {
          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            return true;
          }
          else {
            return false;
          }
        };
        auto checkP = [&] () {
          return !vis[nx][ny] && s[nx][ny] == 'W';
        };
        if (check() && checkP()) {
          ask(nx, ny);
        }
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && s[i][j] == 'W') {
        ans++;
        ask(i, j);
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}