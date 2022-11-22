/**
 *    author:  HONG-LOU
 *    created: 2022-11-22 11:32:13
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a;
    int x;
    std::cin >> x;
    a.push_back(x);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      std::cin >> x;
      if (x != a.back()) {
        a.push_back(x);
      }
    }
    n = (int) a.size();
    for (int i = 1; i < n - 1; i++) {
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
        ans++;
      }
    }
    bool ok = ans == 1;
    if (!ok) {
      bool cnt = true;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
          cnt = false;
        }
      }
      ok = cnt;
    }
    if (!ok) {
      bool cnt = false;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
          cnt = false;
        }
      }
      ok = cnt;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }  
  return 0;
}