/**
 *    author:  HONG-LOU
 *    created: 2023-05-17 15:06:36
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
    std::vector<int> b(n);
    for (int& i : a) {
      std::cin >> i;
    }
    for (int& i : b) {
      std::cin >> i;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::vector<int> f(n, 0);
    int index = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      while (index < n && b[index] < a[i]) {
        index++;
      }
      f[i] = (index - i);
      if (f[i] < 1) {
        ok = false;
      }
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      // std::cout << f[i] << " \n"[i == n - 1];
      ans *= f[i];
      ans %= (int) (1e9 + 7);
    }
    if (!ok) {
      std::cout << 0 << "\n";
      continue;
    }
    std::cout << ans << "\n";
  }
  return 0;
}