/**
 *    author:  HONG-LOU
 *    created: 2023-02-20 23:15:45
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    sum += a[x - 1];
  }
  std::cout << sum << "\n";
  return 0;
}