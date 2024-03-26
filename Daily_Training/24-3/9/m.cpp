/**
 *    author:  HONG-LOU
 *    created: 2024-03-10 10:54:04
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
  std::vector c(n, std::vector<int>(n, 0));
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  auto check = [&] (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  };
  std::vector vis(n, std::vector<int>(n, 0));
  std::function<void(int, int, int)> dfs = [&] (int x, int y, int sum) {
    char c
  };
  return 0;
}