/**
 *    author:  HONG-LOU
 *    created: 2024-03-28 20:24:45
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
  std::stack<int> s;
  std::vector<int> as;
  for (int i = n - 1; i >= 0; i--) {
    int ans = 0;
    while (!s.empty() && a[i] >= s.top()) {
      s.pop();
      ans++;
    }
    if (s.empty()) {
      ans = 0;
    }
    as.push_back(ans);
    s.push(a[i]);
  }
  std::reverse(as.begin(), as.end());
  for (int i = 0; i < n; i++) {
    as[i] += i + 2;
  }
  as[n - 1] = 0;
  for (auto x : as) {
    std::cout << x << ' ';
  }
  return 0;
}