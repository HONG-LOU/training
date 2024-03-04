/**
 *    author:  HONG-LOU
 *    created: 2023-12-18 15:09:03
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
    std::vector<int> a;
    std::string ans = "";
    for (int i = n - 1; i >= 0; i--) {
      if (a.empty() || s[i] >= s[a.back()]) {
        a.push_back(i);
      }
      else {
        ans += s[i];
      }
    }
    std::reverse(ans.begin(), ans.end());
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < (int) a.size(); i++) {
      ans += s[a[i]];
    }
    int oo = 1;
    for (int i = 1; i < (int) a.size(); i++) {
      if (s[a[i]] == s[a[0]]) {
        oo++;
      }
    }
    if (std::is_sorted(ans.begin(), ans.end())) {
      std::cout << (int) ans.size() - oo << "\n";
    }
    else {
      std::cout << -1 << "\n";
    }
  }
  return 0;
}