/**
 *    author:  HONG-LOU
 *    created: 2023-06-10 15:38:52
**/
#include <bits/stdc++.h>

#define int long long

int cnt[2000010], x[3030], y[3030];
std::map<std::pair<int, int>, int> vis;

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i], vis[{x[i], y[i]}] = 1;
  }
  auto dis = [&] (int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  };
  long long ans = 0, line = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      ans += cnt[dis(i, j)], cnt[dis(i, j)]++;
      if (vis[{2 * x[i] - x[j], 2 * y[i] - y[j]}] == 1) line++;
    }
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      cnt[dis(i, j)] = 0;
    }
  }
  std::cout << ans - line / 2 << "\n";
  return 0;
}