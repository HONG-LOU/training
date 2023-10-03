/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 17:27:42
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int N, V;
  std::cin >> N >> V;
  std::vector<int> f(V + 1, 0);
  for (int i = 0; i < N; i++) {
    int v, w;
    std::cin >> v >> w;
    for (int j = v; j <= V; j++) {
      f[j] = std::max(f[j], f[j - v] + w);
    }
  }
  std::cout << f[V] << "\n";
  return 0;
}