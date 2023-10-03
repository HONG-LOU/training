/**
 *    author:  HONG-LOU
 *    created: 2023-08-24 22:16:40
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
      std::cin >> s[i];
    }
    bool v, ii, k, a;
    v = false;
    ii = false;
    k = false;
    a = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        char c = s[j][i];
        if (!v && c == 'v') {
          v = true;
          break;
        }
        if (!ii && v && c == 'i') {
          ii = true;
          break;
        } 
        if (!k && ii && c == 'k') {
          k = true;
          break;
        }
        if (!a && k && c == 'a') {
          a = true;
          break;
        }
      }
    }
    if (v && ii && k && a) {
      std::cout << "YES\n";
    }
    else {
      std::cout << "NO\n";
    }
  }
  return 0;
}