/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 14:57:35
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i]--;
    }
    std::vector<int> cnt(n);
    // cnt : each number count
    std::vector<std::vector<int>> at(n);
    // at : a[i] at index i
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
      at[a[i]].push_back(i);
    }
    std::vector<int> twos;
    std::vector<int> zeros;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (cnt[i] == 0) {
        zeros.push_back(i);
      }
      if (cnt[i] == 2) {
        twos.push_back(i);
      }
      if (cnt[i] > 2) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << "NO" << "\n";
      continue;
    }
    auto p = a;
    auto q = a;
    int k = (int) twos.size();
    for (int i = 0; i < k; i++) {
      if (twos[i] < zeros[i]) {
        ok = false;
        break;
      }
      int v = twos[i];
      p[at[v][0]] = zeros[i];
      q[at[v][1]] = zeros[i];
    }
    if (ok) {
      std::cout << "YES" << "\n";
      for (int i = 0; i < n; i++) {
        std::cout << p[i] + 1 << " \n"[i == n - 1];
      }
      for (int i = 0; i < n; i++) {
        std::cout << q[i] + 1 << " \n"[i == n - 1];
      }
    }
    else {
      std::cout << "NO" << "\n";
    }
  }  
  return 0;
}