/**
 *    author:  HONG-LOU
 *    created: 2022-11-17 22:29:01
**/
#include <bits/stdc++.h>

long long N = (long long) 1e12 + 10;

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::vector<long long> base;
  auto make_fund = [&] () {
    long long a = 1,b = 1;
    std::set<long long> se;
    while (a <= N) {
      se.insert(a);
      a *= 2;
    }
    a = 1;
    while (a <= N){
      a *= b;
      se.insert(a);
      b++;
    }
    for (long long x : se) {
      base.push_back(x);
    }
  };
  make_fund();
  std::reverse(base.begin(), base.end());
  int tt;
  std::cin >> tt;
  while (tt--) {
    long long n;
    std::cin >> n;
    int ans = 60;
    std::vector<bool> cnt((int) base.size(), false);
    std::function<void(long long, int)> dfs = [&] (long long now, int deep) {
      if (now == 0) {
        ans = std::min(ans, deep);
        return;
      }
      for (int i = 0; i < (int) base.size(); i++) {
        if (!cnt[i] && now >= base[i]) {
          now -= base[i];
          cnt[i] = true;
          dfs(now, deep + 1);
          now += base[i];
        }
      }
    };
    dfs(n, 0);
    std::cout << (ans == 60 ? -1 : ans) << "\n";
  }
  return 0;
}