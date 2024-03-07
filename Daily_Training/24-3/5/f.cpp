/**
 *    author:  HONG-LOU
 *    created: 2024-03-05 20:29:38
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  while (q--) {
    int x;
    std::cin >> x;
    int index = std::lower_bound(a.begin(), a.end(), x) - a.begin();
    if (a[index] == x) {
      std::cout << index + 1 << ' ';
    }
    else {
      std::cout << -1 << '\n';
    }
  }
  return 0;
}