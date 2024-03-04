/**
 *    author:  HONG-LOU
 *    created: 2023-12-10 13:49:37
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    std::vector<std::pair<char ,int>> b;
    std::vector<std::pair<char, int>> B;
    int len = (int) s.size();
    for (int i = 0; i < len; i++) {
      if (s[i] == 'b') {
        if (!b.empty()) {
          b.pop_back();
        }
      }
      else if (s[i] == 'B') {
        if (!B.empty()) {
          B.pop_back();
        }
      }
      else {
        if (s[i] >= 'a' && s[i] <= 'z') {
          b.push_back({s[i], i});
        }
        else {
          B.push_back({s[i], i});
        }
      }
    }
    std::vector<std::pair<char, int>> ans = b;
    ans.insert(ans.end(), B.begin(), B.end());
    std::sort(ans.begin(), ans.end(), [&] (std::pair<char, int> x, std::pair<char, int> y) {
      return x.second < y.second;
    });
    for (auto x : ans) {
      std::cout << x.first;
    }
    std::cout << "\n";
  }
  return 0;
}