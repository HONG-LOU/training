/**
 *    author:  HONG-LOU
 *    created: 2024-03-10 20:14:08
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::ifstream in;
  in.open("1.in");
  long long w;
  in >> w;
  int n;
  in >> n;
  std::vector<long long> g(n);
  for (int i = 0; i < n; i++) {
    in >> g[i];
  }
  long long ans = 0;
  std::vector<int> vis(n, 0);
  std::function<void(long long)> dfs = [&] (long long sum) {
    ans = std::max(ans, sum);
    for (int i = 0; i < n; i++) {
      if (!vis[i] && sum + g[i] <= w) {
        vis[i] = 1;
        dfs(sum + g[i]);
        vis[i] = 0;
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (g[i] <= w) {
      vis[i] = 1;
      dfs(g[i]);
      vis[i] = 0;
    }
  }
  std::cout << ans << "\n";
  in.close();
  return 0;
}