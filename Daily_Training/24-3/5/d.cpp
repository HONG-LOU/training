/**
 *    author:  HONG-LOU
 *    created: 2024-03-05 19:19:58
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i] + c;
    int index = std::lower_bound(a.begin(), a.end(), x) - a.begin();
    if (index != n && index != i) {
      ans++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}