/**
 *    author:  HONG-LOU
 *    created: 2023-09-22 16:55:27
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      std::cin >> h[i];
    }
    int ans = 0, cnt = 0, index = 0;
    for (int i = 0; i < n; i++) {
      while (index < n && (index <= i || h[index - 1] % h[index] == 0) && cnt + a[index] <= k) {
        cnt += a[index], index++;
      }
      ans = std::max(ans, index - i);
      cnt -= a[i];
    }
    std::cout << ans << "\n";
  }
  return 0;
}