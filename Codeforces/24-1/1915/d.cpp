/**
 *    author:  HONG-LOU
 *    created: 2024-01-17 17:18:22
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<char, int> a; // v
    a['a'] = 1;
    a['e'] = 1;
    std::map<char, int> b; // c
    b['b'] = 1;
    b['c'] = 1;
    b['d'] = 1;
    for (int i = 0; i < n; i++) {
      if (b[s[i]] && a[s[i + 1]] && b[s[i + 2]] && (i + 3 == n || b[s[i + 3]])) {
        std::cout << s[i] << s[i + 1] << s[i + 2];
        if (i + 3 != n) {
          std::cout << '.';
        }
        i += 2;
      }
      else {
        std::cout << s[i] << s[i + 1];
        if (i + 2 != n) {
          std::cout << '.';
        }
        i += 1;
      }
    }
    std::cout << "\n";
  }
  return 0;
}