/**
 *    author:  HONG-LOU
 *    created: 2022-11-17 17:01:20
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> l;
  std::vector<int> r;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (int j = 0; j < (int) s.size(); j++) {
      if (s[j] == '(') {
        cnt++;
      }
      else {
        cnt--;
      }
    }
    ans += cnt;
    if (cnt > 0) {
      l.push_back(i + 1);
    }
    else {
      r.push_back(i + 1);
    }
  }
  if (ans != 0) {
    std::cout << "impossible\n";
    return 0;
  }
  for (int i : l) {
    std::cout << i << '\n';
  }
  for (int i : r) {
    std::cout << i << '\n';
  }
  return 0;
}