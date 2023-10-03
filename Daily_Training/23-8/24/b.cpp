/**
 *    author:  HONG-LOU
 *    created: 2023-08-24 22:49:09
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
    std::vector<int> ans;
    ans.push_back(a[0]);
    int sz = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] >= ans[sz - 1]) {
        ans.push_back(a[i]);
        sz++;
      }
      else {
        ans.push_back(a[i]);
        ans.push_back(a[i]);
        sz += 2;
      }
    }
    std::cout << sz << "\n";
    for (int i = 0; i < sz; i++) {
      std::cout << ans[i] << " \n"[i == sz - 1];
    }
  }
  return 0;
}