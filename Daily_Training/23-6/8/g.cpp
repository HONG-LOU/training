/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 17:12:16
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::map<long long, bool> c;
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long x;
    std::cin >> x;
    int cnt = x;
    while (x <= n) {
      
      x *= cnt;
      c[x] = true;
    }
  }
  std::cout << n - (int) c.size() << "\n";
  return 0;
}