/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 16:56:33
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::map<std::pair<int, int>, int> c;
  const int mod = (int) 1e9 + 7;
  std::function<int(int, int)> dfs = [&] (int i, int j) {
    if (j == 1) {
      return i;
    }
    if (c[{i, j}]) {
      return c[{i, j}];
    }
    return c[{i, j}] = (dfs(i - 1, j - 1) + dfs(i - 1, j)) % mod;
  };
  c[{1, 1}] = 1;
  int tt;
  std::cin >> tt;
  while (tt--) {
    int x, y;
    std::cin >> x >> y;
    std::cout << dfs(x, y) << "\n";
  }
  return 0;
}