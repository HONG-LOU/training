/**
 *    author:  HONG-LOU
 *    created: 2023-01-18 14:31:39
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int cnt = 0, ans = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ) {
      while (a[i] <= cnt && i < n) {
        cnt++;
        i++;
      }
      ans++;
      while (a[i] > cnt) {
        cnt++;
        i++;
        if (i >= n) {
          break;
        }
      }
    }
    std::cout << ans << "\n";
  }  
  return 0;
}