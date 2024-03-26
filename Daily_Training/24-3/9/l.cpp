/**
 *    author:  HONG-LOU
 *    created: 2024-03-10 10:34:45
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> g(n);
  for (int i = 0; i < n; i++) {
    std::cin >> g[i];
  }
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  int ans = 0;
  auto check = [&] (int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
  };
  std::function<void(int, int)> bfs = [&] (int x, int y) {
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> vis(n, std::vector<int>(n, 0));
    q.push({x, y});
    ans = 1;
    while (!q.empty()) {
      auto s = q.front();
      q.pop();
      vis[s.first][s.second] = 1;
      for (int i = 0; i < 4; i++) {
        char c = (g[s.first][s.second] == '0' ? '1' : '0');
        int nx = (s.first + dx[i]);
        int ny = (s.second + dy[i]);
        if (check(nx, ny) && vis[nx][ny] == 0 && g[nx][ny] == c) {
          vis[nx][ny] = 1;
          ans++;
          q.push({nx, ny});
        } 
      }
    }
  };
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    bfs(x, y);
    std::cout << ans << "\n";
  }
  return 0;
}