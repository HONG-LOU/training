/**
 *    author:  HONG-LOU
 *    created: 2023-06-18 16:24:42
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
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int ans = 0;
    int sum = std::accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n && sum < 0; i++) {
      if (a[i] == -1) {
        a[i] = 1;
        ans++;
        sum += 2;
      }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      cnt *= a[i];
    }
    if (cnt == -1) {
      ans++;
    }
    std::cout << ans << "\n";
  }
  return 0;
}