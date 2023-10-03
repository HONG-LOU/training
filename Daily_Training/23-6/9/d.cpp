/**
 *    author:  HONG-LOU
 *    created: 2023-06-10 15:51:59
**/
#include <bits/stdc++.h>

int n, m, k;

bool ok = false;

int mn = (int) 1e9;

bool vis[1010][1010][2][12] = {false};
char s[1010][1010];

bool check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, char now, int cnt, int step) {
  std::cout << x << ' ' << y << ' ' << now << ' ' << cnt << ' ' << step << "\n";
  vis[x][y][now - 'A'][cnt] = true;
  if (x == n && y == m) {
    ok = true;
    mn = std::min(mn, step);
    return;
  }
  char c = now;
  if (cnt == k) {
    if (now == 'A') {
      c = 'B';
    }
    else {
      c = 'A';
    }
    cnt = 0;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (check(nx, ny) && s[nx][ny] == c && !vis[nx][ny][c - 'A'][cnt + 1]) {
      dfs(nx, ny, c, cnt + 1, step + 1);
    }
  }
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> s[i][j];
    }
  }
  dfs(1, 1, 'A', 1, 0);
  std::cout << mn << "\n";
  return 0;
}