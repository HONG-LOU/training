/**
 *    author:  HONG-LOU
 *    created: 2023-12-11 15:06:18
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
    std::reverse(a.begin(), a.end());
    auto b = a.insert(a.end(), a.begin(), a.end());
    std::vector<int> p, q;
    p.push_back(0);
    q.push_back(0);
    for (int i = 0; i < n * 2 - 1; i++) {
      p.push_back(a[i] >= a[i + 1] ? p.back() + 1 : 0);
      q.push_back(a[i] <= a[i + 1] ? q.back() + 1 : 0);
    }
    int mn = (int) 1e9;
    for (int i = n - 1; i < (int) p.size(); i++) {
      if (p[i] == n - 1) {
        mn = std::min({mn, i - n + 1, (int) p.size() - i + 1});
      }
      if (q[i] == n - 1) {
        mn = std::min({mn, (int) p.size() - i, i - n + 2});
      }
    }
    std::cout << (mn == (int) 1e9 ? -1 : mn) << "\n";
  }
  return 0;
}