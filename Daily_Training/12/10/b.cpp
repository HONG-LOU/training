/**
 *    author:  HONG-LOU
 *    created: 2022-12-10 19:12:09
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string a, b;
  std::cin >> a >> b;
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  std::vector<int> c(std::max((int) a.size(), (int) b.size()));
  for (int i = 0; i < (int) c.size(); i++) {
    c[i] = ((i >= (int) a.size() ? 0 : (a[i] - '0')) + (i >= (int) b.size() ? 0 : (b[i] - '0')));
  }
  std::string s;
  for (int i = 0; i < (int) c.size(); i++) {
    s += ((c[i] % 10) + '0');
    if (c[i] >= 10) {
      if (i >= (int) c.size() - 1) {
        s += (c[i] / 10 + '0');
      }
      else {
        c[i + 1] += c[i] / 10;
      }
    }
  }
  std::reverse(s.begin(), s.end());
  std::cout << s << std::endl;
  return 0;
}