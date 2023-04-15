/**
 *    author:  HONG-LOU
 *    created: 2023-03-17 10:47:34
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  std::function<int(int)> find = [&] (int x) {
    return x ==  a[x] ? x : a[x] = find(a[x]);
  };
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    a[find(u)] = find(v);
  }
  for (int i = 0; i < q; i++) {
    int u, v;
    std::cin >> u >> v;
    if (find(u) == find(v)) {
      std::cout << "Yes\n";
    }
    else {
      std::cout << "No\n";
    }
  }
  return 0;
}