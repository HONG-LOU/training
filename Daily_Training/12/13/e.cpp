/**
 *    author:  HONG-LOU
 *    created: 2022-12-13 20:11:10
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i < 10) {
        ans++;
      }
      if (i < 100) {
        if (i % 10 == 0) {
          ans++;
        }  
      }
      else if (i < 1000) {
        if (i % 100 == 0) {
          ans++;
        }
      }
      else if (i < 10000) {
        if (i % 1000 == 0) {
          ans++;
        }
      }
      else if (i < 100000) {
        if (i % 10000 == 0) {
          ans++;
        }
      }
      else if (i < 1000000) {
        if (i % 100000 == 0) {
          ans++;
        }
      }
    }
    std::cout << ans << "\n";
  }  
  return 0;
}