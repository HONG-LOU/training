/**
 *    author:  HONG-LOU
 *    created: 2023-03-12 19:03:41
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::map<int, int> x;
  for (int i = 0; i < n; i++) {
    if (x[a[a[i] - 1]] == 0) x[a[a[i] - 1]] += 1;
  }
  int ans = 0;
  std::vector<int> value;
  for (int i = 0; i < n; i++) {
    if (x[a[i]] == 0) {
      ans++;
      value.push_back(i + 1);
    }
  }
  std::cout << ans << "\n";
  for (int res : value) {
    std::cout << res << ' ';
  }
  return 0;
}