#include <bits/stdc++.h>

// #define int long long

signed main () {
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
  int mx = a[0] + b[0];
  for (int i = 1; i < n; i++) {
    mx = std::min(mx, a[i] + b[i]);
  }
  int l = 0, r = mx + 1;
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
  std::vector<int> load(mx + 1);
  return 0;
}