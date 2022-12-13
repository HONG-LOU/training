/**
 *    author:  HONG-LOU
 *    created: 2022-12-13 10:58:25
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  int n = (int) s.size();
  bool ok = true;
  int ans = 0;
  if (n != 8) {
    ok = false;
  }  
  if (!ok) {
    std::cout << "No\n";
    return 0;
  }
  if ((s[0] < 'A' || s[0] > 'Z') || (s[7] < 'A' || s[7] > 'Z')) {
    ok = false;
  }
  for (int i = 1; i < 7; i++) {
    if (s[i] > '9' || s[i] < '0') {
      ok = false;
    }
    else {
      ans = ans * 10 + (s[i] - '0');
    }
  }
  if (ans < 100000 || ans > 999999) {
    ok = false;
  }
  if (!ok) {
    std::cout << "No" << std::endl;
  }
  else {
    std::cout << "Yes\n";
  }
  return 0;
}