/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 17:15:41
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int l, n, m;
  std::cin >> l >> n >> m;
  std::vector<int> a(n);
  std::vector<int> dis(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i < n - 1; i++) {
    dis[i] = a[i] - a[i - 1];
  }
  dis[0] = a[0];
  dis[n - 1] = l - a[n - 1];
  for (int i = 0; i < n; i++) {
    std::cout << dis[i] << " \n"[i == n - 1];
  }
  std::sort(a.begin(), a.end(), [&] (int i, int j) {
    return dis[(i - 1 + n + n) % n] > dis[(j - 1 + n + n) % n];
  });
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}