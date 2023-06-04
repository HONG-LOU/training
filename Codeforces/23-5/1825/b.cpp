/**
 *    author:  HONG-LOU
 *    created: 2023-05-09 12:53:34
**/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ans1, ans2;

#define int long long

// 这是真没看懂，一样的式子结果不一样, 式子不一样吗？
// max --- min
// ans = (n - 1) * (a[0] - a[n * m - 2]);
// ans += (m - 1) * n * (a[0] - a[n * m - 1]);

// res = (n - 1) * (a[1] - a[n * m - 1]);
// res += (m - 1) * n * (a[0] - a[n * m - 1]);

// max(ans, res) ??? why not the same

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    if (n > m) {
      std::swap(n, m);
    }
    std::cin >> n >> m;
    std::vector<int> b(n * m + 1);
    for (int i = 0; i < n * m; i++) {
      std::cin >> b[i + 1];
    }
    std::sort(b.begin() + 1, b.end());
    ll ma = b[n * m], mi1 = b[1], mi2 = b[2];
    ans1 = 0;
    ans1 += (ma - mi1) * (n - 1) * (m - 1);
    ans1 += (ma - max(mi1, mi2)) * (min(n, m) - 1);
    ans1 += (ma - min(mi1, mi2)) * (max(n, m) - 1);
    ll mi = b[1], ma1 = b[n * m], ma2 = b[m * n - 1];
    ans2 = 0;
    ans2 += (ma1 - mi) * (n - 1) * (m - 1);
    ans2 += (max(ma1, ma2) - mi) * (max(n, m) - 1);
    ans2 += (min(ma1, ma2) - mi) * (min(n, m) - 1);
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}