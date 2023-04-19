#include <bits/stdc++.h>

auto main () -> int {
  int n, m;
  std::cin >> n >> m;
  std::map<std::string, std::pair<std::set<std::string>, std::set<std::string>>> x;
  for (int i = 0; i < m; i++) {
    std::string a, b;
    std::cin >> a >> b;
    if (a[0] <= '9' && a[0] >= '0') {
      x[b].second.insert(a);
    }
    else {
      x[b].first.insert(a);
    }
  }
  char q;
  while (std::cin >> q) {
    if (q == 'E') {
      break;
    }
    else if (q == 'T') {
      std::string s;
      std::cin >> s;
      
    }
    std::string s;
    std::cin >> s;
    long long ans = 0;
    std::map<std::string, bool> c;
    std::function<void(std::string)> dfs = [&] (std::string ss) {
      ans += (int) x[s].second.size();
      c[ss] = true;
      for (auto st : x[ss].first) {
        if (!c[st]) {
          dfs(st);
        }
      }
    };
    dfs(s);
    std::cout << ans << "\n";
  }
  return 0;
}