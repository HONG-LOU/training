/**
 *    author:  HONG-LOU
 *    created: 2023-01-18 14:53:18
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> c(26, 0);
    int mx = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
      c[s[i] - 'a']++;
    }
    std::sort(c.begin(), c.end(), std::greater<int>());
    for (int i = 0; i < 26; i++) {
      if (n % c[i] == 0) {
        
      }
    }
  }  
  return 0;
}