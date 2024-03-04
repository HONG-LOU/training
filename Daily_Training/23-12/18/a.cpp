/**
 *    author:  HONG-LOU
 *    created: 2023-12-18 10:12:46
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
    char cnt = s[n - 1];
    std::vector<int> c;
    c.push_back(n - 1);
    std::map<int, bool> m;
    m[n - 1] = true;
    int oo = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] >= cnt) {
        cnt = s[i];
        c.push_back(i);
        m[i] = true;
      }
    }
    int len = (int) c.size();
    std::reverse(c.begin(), c.end());
    if (std::is_sorted(s.begin(), s.end())) {
      std::cout << 0 << "\n";
      continue;
    }
    for (int i = 0; i < len; i++) {
      if (s[c[0]] == s[c[i]]) {
        oo++;
      }
      else {
        break;
      }
    }
    std::string ans = "";
    for (int i = 0; i < n; i++) {
      if (!m[i]) {
        ans += s[i];
      }
      else {
        ans += s[c.back()];
        c.pop_back();
      }
    }
    // std::cout << ans << "\n";
    if (std::is_sorted(ans.begin(), ans.end())) {
      std::cout << len - oo << "\n";
    }
    else {
      std::cout << -1 << "\n";
    }
    // std::cout << (int) c.size() << "\n";
  }
  return 0;
}