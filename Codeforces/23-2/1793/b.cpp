/**
 *    author:  HONG-LOU
 *    created: 2023-02-13 14:32:13
**/
#include <bits/stdc++.h>

void solve() {
    int x, y;
    std::cin >> x >> y;
    std::vector<int> ans;
    for (int i = x; i > y; i--)
        ans.push_back(i);
    for (int i = y; i < x; i++)
        ans.push_back(i);
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}