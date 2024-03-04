/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 15:50:57
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
  auto check = [&] (int x) {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return 0;
      }
    }
    return 1;
  };
  std::vector<std::vector<int>> s(n, std::vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= a[i]; j++) {
      if (a[i] % j == 0 && check(j)) {
        s[i].push_back(j);
      }
    }
  }
  int mn = (int) 1e9;
  std::map<int, int> m;
  int cnt[11] = {0};
  std::function<void(int, int)> dfs = [&] (int deep, int sum) {
    if (deep == n) {
      // mn = std::min(mn, sum);
      if (sum < mn) {
        for (int i = 0; i < 4; i++) {
          std::cout << cnt[i] << " \n"[i == 3];
        }
        mn = sum;
      }
      return;
    }
    for (int x : s[deep]) {
      if (m[x] == 0) {
        m[x] = 1;
        cnt[deep] = x;
        dfs(deep + 1, sum + x);
        m[x] = 0;
      }
    }
  };
  dfs(0, 0);
  std::cout << mn;
  return 0;
}