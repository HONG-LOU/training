/**
 *    author:  HONG-LOU
 *    created: 2022-12-31 10:18:50
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::map<int, std::pair<long long, int>> x;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    long long cnt = a[i] * a[i];
    long long p = 0, q = 0;
    while (cnt <= (int) 1e6) {
      if (x[cnt].second > 0) {
        p += x[cnt].second;
        q += x[cnt].first;
      }
      cnt *= a[i];
    }
    q %= 99999;
    std::cout << p << ' ' << q << "\n";
    x[a[i]].first += a[i];
    x[a[i]].second += 1;
  }
  return 0;
}