/**
 *    author:  HONG-LOU
 *    created: 2023-05-17 14:47:46
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
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int index = 0;
    long long ans = 1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      while (b[index] < a[i] && index < n) {
        index++;
      }
      if (index - i == 0) {
        index = 1;
      }
      if (index - i < 0) {
        ok = false;
        break;
      }
      // std::cout << index - i << ' ';
      ans *= (index - i);
      ans %= (int) (1e9 + 7);
    }
    if (!ok) {
      ans = 0;
    }
    std::cout << ans << "\n";
  }
  return 0;
}