/**
 *    author:  HONG-LOU
 *    created: 2023-03-21 10:48:20
**/
#include <bits/stdc++.h>

int dis[3] = {-1, 0, 1};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<std::vector<bool>> used(n, std::vector<bool>(m));
  std::function<bool(int, int)> dfs = [&] (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
      return false;
    }
    if ()
    return false;
  };
  return 0;
}