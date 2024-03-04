/**
 *    author:  HONG-LOU
 *    created: 2024-01-27 20:08:20
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  int k;
  std::cin >> k;
  std::vector<int> ab(s.length(), 0);
  for (int i = 0; i < s.length() && k; i++) {
    int pos = -1;
    for (int j = i + 1; j < s.length(); j++) {
      if (s[j] < s[i] && s[j] != '0') {
        ab[i] = 1;
        k--;
        break;
      }
    }
  }
  std::string ans = "";
  for (int i = 0; i < s.length() - k; i++) {
    if (!ab[i]) {
      ans += s[i];
    }
  }
  for (int i = 0; i < ans.length(); i++) {
    if (ans[i] != '0') {
      for (int j = i; j < ans.length(); j++) {
        std::cout << ans[j];
      }
      break;
    }
  }
  return 0;
}