/**
 *    author:  HONG-LOU
 *    created: 2023-03-24 10:40:07
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::vector<int> b(m);
  std::vector<int> c;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    c.push_back(a[i]);
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
    c.push_back(b[i]);
  }
  std::sort(c.begin(), c.end());
  std::map<int, int> x;
  for (int i = 0; i < n + m; i++) {
    x[c[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    std::cout << x[a[i]] << " \n"[i == n - 1];
  }
  for (int i = 0; i < m; i++) {
    std::cout << x[b[i]] << " \n"[i == m - 1];
  }
  return 0;
}