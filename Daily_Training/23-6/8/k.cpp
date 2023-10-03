/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 21:19:11
**/
#include <bits/stdc++.h>

#define int long long

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  auto check = [&] (int x) {
    int cnt = m;
    for (int i = 0; i < n; i++) {
      if (a[i] < x && b[i] >= x - a[i]) {
        cnt -= x - a[i];
      }
      if (a[i] < x && b[i] < x - a[i]) {
        return false;
      }
      if (cnt < 0) {
        return false;
      }
    }
    return true;
  };
  int l = 0, r = (int) 1e9 + 7;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  std::cout << l << "\n";
  return 0;
}