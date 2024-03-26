/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 17:09:49
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::map<std::string, std::string> mp;
  std::map<int, int> f;
  for (int i = 0; i < n; i++) {
    f[i] = i;
  }
  std::function<std::string(std::string)> get = [&] (std::string s) {
    return s == mp[s] ? s : mp[s] = get(mp[s]);
  };
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    mp[s] = s;
  }
  for (int i = 0; i < m; i++) {
    std::string x, y;
    std::cin >> x >> y;
    mp[get(x)] = get(y);
  }
  int q;
  std::cin >> q;
  while (q--) {
    std::string x, y;
    std::cin >> x >> y;
    if (get(x) == get(y)) {
      std::cout << "Yes.\n";
    }
    else {
      std::cout << "No.\n";
    }
  }
  return 0;
}



































000000000
010101001
010101001
001010101
110101011