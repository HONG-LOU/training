/**
 *    author:  HONG-LOU
 *    created: 2022-11-17 23:35:04
**/
#include <bits/stdc++.h>

#define int long long

const int N = (int) 1e6 + 10;
bool buc[N * 20];
int n, m, ans = 1, a[30], vis[N], now;
std::unordered_map<int, int> mp;

auto main() -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> n >> m;
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= m; j++) {
      now += buc[i * j] ^ 1;
      buc[i * j] = 1;
    }
    a[i] = now;
  }
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      int x = i, cnt = 0;
      while (x <= n) {
        cnt++;
        vis[x] = 1;
        x *= i;
      }
      ans += a[cnt];
    }
  }
  std::cout << ans << "\n";
  return 0;
}