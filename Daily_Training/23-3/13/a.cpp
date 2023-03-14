/**
 *    author:  HONG-LOU
 *    created: 2023-03-13 19:38:09
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i - 1];
  }
  for (int i = 0; i < m; i++) {
    std::prev_permutation(a.begin(), a.end());
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}