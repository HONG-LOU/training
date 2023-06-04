/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 15:00:54
**/
#include <bits/stdc++.h>

#define int long long

int c[2100][2100] = {0};

auto main () -> signed {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int cnt = 1;
  std::map<int, std::pair<int, int>> po;
  for (int i = 1; i <= 2023; i++) {
    for (int j = 1; j <= i; j++) {
      po[cnt] = {i, j};
      c[i][j] = cnt++;
    }
  }

  int tt;
  std::cin >> tt;
  std::map<int, bool> x;
  x[1] = true;
  int base = 2;
  cnt = 2;
  while (base <= 2023) {
    x[base] = true;
    base += cnt;
    cnt += 1;
  }
  int top = base + 2022;
  base = 3;
  cnt = 3;
  while (base <= top) {
    x[base] = true;
    base += cnt;
    cnt += 1;
  }
  auto check = [&] (int xx) {
    return x[xx];
  };
  while (tt--) {
    int n;
    std::cin >> n;
    int xr = n;
    long long sum = 0;
    std::map<std::pair<int, int>, bool> vis;
    std::function<void(int, int, int)> dfs = [&] (int p, int xi, int yi) {
      if (xi == 0 || yi > xi || yi == 0 || vis[{xi, yi}]) {
        return;
      }
      sum += p * p;
      vis[{xi, yi}] = true;
      dfs(c[xi - 1][yi], xi - 1, yi);
      dfs(c[xi - 1][yi - 1], xi - 1, yi - 1);
    };
    int px = po[xr].first, py = po[xr].second;
    dfs(xr, px, py);
    std::cout << sum << "\n";
  }
  return 0;
}