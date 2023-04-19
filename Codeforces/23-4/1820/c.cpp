/**
 *    author:  HONG-LOU
 *    created: 2023-04-16 16:46:44
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  auto Mex = [&] (std::vector<int> a) {
    std::sort(a.begin(), a.end());
    if (a[0] > 0) {
      return 0;
    }
    for (int i = 1; i < (int) a.size(); i++) {
      if (a[i] > a[i - 1] + 1) {
        return a[i - 1] + 1;
      }
    }
    return a.back() + 1;
  };
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int m = Mex(a);
    int L = n + 1;
    int R = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == m + 1) {
        L = std::min(L, i);
        R = std::max(R, i);
      }
    }
    if (R == -1) {
      std::cout << (m == n ? "No" : "Yes") << "\n";
    }
    else {
      for (int i = L; i <= R; i++) {
        a[i] = m;
      }
      std::cout << (Mex(a) == m + 1 ? "Yes" : "No") << "\n";
    }
  }
  return 0;
}