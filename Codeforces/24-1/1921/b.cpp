/**
 *    author:  HONG-LOU
 *    created: 2024-01-15 22:47:19
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    int ans = 0;
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '0') {
        sa++;
      }
      if (a[i] == '0' && b[i] == '1') {
        sb++;
      }
    }
    // std::cout << sa << ' ' << sb << "\n";
    std::cout << std::max(sa, sb) << "\n";
  }
  return 0;
}