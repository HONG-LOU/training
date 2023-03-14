/**
 *    author:  HONG-LOU
 *    created: 2023-02-17 10:28:49
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(b.begin(), b.end());
    a += b;
    int cnt = 0;
    for (int i = 0; i < n + m - 1; i++) {
      if (a[i] == a[i + 1]) {
        cnt++;
      }
    }
    std::cout << (cnt <= 1 ? "YES\n" : "NO\n");
  }
  return 0;
}