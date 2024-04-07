/**
 *    author:  HONG-LOU
 *    created: 2024-03-28 20:38:02
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::vector<int> b(n + 1, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  while (m--) {
    int l, r, c;
    std::cin >> l >> r >> c;
    b[r] -= c;
    b[l - 1] += c;
  }
  for (int i = 1; i <= n; i++) {
    b[i] += b[i - 1];
  }
  for (int i = 0; i < n; i++) {
    a[i] += b[i];
  }
  std::cout << *std::min_element(a.begin(), a.end()) << "\n";
  return 0;
}