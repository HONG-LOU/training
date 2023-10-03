/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 16:44:28
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, V;
  std::cin >> n >> V;
  std::vector<int> f(V + 1, 0);
  for (int i = 0; i < n; i++) {
    int v, w;
    std::cin >> v >> w;
    for (int j = V; j >= v; j--) {
      f[j] = std::max(f[j], f[j - v] + w);
    }
  }
  int mx = 0;
  for (int i = 0; i < V + 1; i++) {
    mx = std::max(mx, f[i]);
  }
  std::cout << mx << "\n";
  return 0;
}