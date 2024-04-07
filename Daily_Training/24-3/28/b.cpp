/**
 *    author:  HONG-LOU
 *    created: 2024-03-28 19:43:27
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::map<int, int> mp;
  std::queue<int> q;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    if (!mp[x]) {
      if (q.size() < n) {
        q.push(x);
      }
      else {
        mp[q.front()] = 0;
        q.pop();
        q.push(x);
      }
      mp[x] = 1;
      ans++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}