/**
 *    author:  HONG-LOU
 *    created: 2023-02-13 14:14:43
**/
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if (m >= n)
        cout << min(a, b) * n << '\n';
    else
        cout << min(n * b, (n / (m + 1)) * a * m + 
        (n - (n / (m + 1)) * (m + 1)) * min(a, b)) << '\n';
}  //注意要开long long！

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}