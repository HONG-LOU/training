/**
 *    author:  HONG-LOU
 *    created: 2022-11-26 15:55:45
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::map<int, int> mp;
  int mx = 0;
  int mxs = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    mp[a[i]]++;
    if (mp[a[i]] > mx) {
      mx = mp[a[i]];
      mxs = a[i];
    }
  }  
  std::sort(a.begin(), a.end());
  if (m >= n - 1) {
    std::cout << 0 << "\n";
    return 0;
  }
  int l = 0, r = n - 1;
  while ((a[l] != mxs || a[r]) != mxs && m > 0) {
    if (a[l] == mxs) {
      a[r] = 
    }
  }
  return 0;
}