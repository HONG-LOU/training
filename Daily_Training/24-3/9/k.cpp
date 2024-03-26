/**
 *    author:  HONG-LOU
 *    created: 2024-03-10 10:24:26
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
  int dx[4] = {0, 1, -1, 0};
  int dy[4] = {1, 0, 0, -1};
  int ans = 0;
  auto check = [&] (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  };
  std::vector<std::vector<int>> vis(n, std::vector<int>(n, 0));
  std::function<void(int, int)> dfs = [&] (int x, int y) {
    ans++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      char c = (s[x][y] == '0' ? '1' : '0');
      int nx = x + dx[i], ny = y + dy[i];
      if (check(nx, ny) && s[nx][ny] == c && vis[nx][ny] == 0) {
        dfs(nx, ny);
      }
    }
  };
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    x -= 1, y -= 1;
    ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        vis[i][j] = 0;
      }
    }
    dfs(x, y);
    std::cout << ans << "\n";
  }
  return 0;
}