/**
 *    author:  HONG-LOU
 *    created: 2024-03-01 16:05:23
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<int> a(n);
  std::vector<int> b(m);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int y = x - a[i];
    int index = std::lower_bound(b.begin(), b.end(), y) - b.begin();
    if (b[index] + a[i] == x) {
      std::cout << i << ' ' << index << "\n";
      break;
    }
  }
  return 0;
}