/**
 *    author:  HONG-LOU
 *    created: 2023-02-18 15:38:36
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::vector<long long> s(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    long long sum = s[r] - s[l - 1];
    std::cout << sum << " ";
    std::cout << (sum % m == 0 ? "Yes\n" : "No\n");
  }
  return 0;
}