/**
 *    author:  HONG-LOU
 *    created: 2023-04-24 21:39:14
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int ans = -1;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    if (a[i] == m && b[i] > mx) {
      ans = i + 1;
      mx = b[i];
    }
  }
  if (ans == -1) {
    for (int i = 0; i < n; i++) {
      if (a[i] == a[0] && b[i] > mx) {
        ans = i + 1;
        mx = b[i];
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}