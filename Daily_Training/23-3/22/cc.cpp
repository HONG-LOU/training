/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 15:14:43
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto b = a;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    if (b[u] == 1) {
      a[v] = 1;
    }
    if (b[v] == 1) {
      a[u] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}