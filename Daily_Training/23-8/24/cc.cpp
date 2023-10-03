/**
 *    author:  HONG-LOU
 *    created: 2023-08-24 23:17:17
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> m;
    int cnt = 1;
    m[1] = cnt;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (i == 0) continue;
      if (a[i] < a[i - 1]) {
        cnt++;
      }
      m[i + 1] = cnt;
    }
    for (int i = 1; i <= n; i++) {
      std::cout << m[i] << " \n"[i == n];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != m[n - i]) {
        ok = false;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}