/**
 *    author:  HONG-LOU
 *    created: 2023-11-10 15:09:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> cnt(n, 0);

  auto pri = [&] () {
    for (int i = 0; i < n; i++) {
      std::cout << cnt[i] << " \n"[i == n - 1];
    }
  };
  
  std::vector<bool> used(n, false);

  std::function<void(int)> ask = [&] (int deep) {
    if (deep == n) {
      pri();
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        cnt[deep] = i + 1;
        used[i] = true;
        ask(deep + 1);
        used[i] = false;
      }
    }
  };

  ask(0);
  return 0;
}