/**
 *    author:  HONG-LOU
 *    created: 2023-02-18 15:19:00
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<std::string> a(n);
  std::vector<std::string> b;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < k && i < n; i++) {
    b.push_back(a[i]);
  }
  std::sort(b.begin(), b.end());
  for (auto s : b) {
    std::cout << s << "\n";
  }
  return 0;
}