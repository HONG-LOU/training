/**
 *    author:  HONG-LOU
 *    created: 2023-04-19 20:24:32
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::map<std::string, std::string> x;
  std::map<std::string, std::string> y;
  std::map<std::string, bool> h;
  std::map<std::string, bool> c;
  std::map<std::string, bool> in;
  for (int i = 0; i < n; i++) {
    std::string a, b;
    std::cin >> a >> b;
    in[a + b] = true;
    int l = (int) b.size();
    if (l < 4) {
      c[a + b] = true;
      continue;
    }
    std::string cnt(b.begin() + l - 4, b.end());
    if (cnt == "sson") {
      x[a] = std::string(b.begin(), b.begin() + l - 4);
      c[a + b] = true;
      h[a + b] = true;
    }
    if (l < 7) continue;
    std::string cnt1(b.begin() + l - 7, b.end());
    if (cnt1 == "sdottir") {
      y[a] = std::string(b.begin(), b.begin() + l - 7);
      c[a + b] = false;
      h[a + b] = true;
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    std::string u1, v1, u2, v2;
    std::cin >> u1 >> v1 >> u2 >> v2;
    if (c[u1 + v1] == c[u2 + v2]) {
      std::cout << "Whatever\n";
      continue;
    }
    if (!in[u1 + v1] || !in[u2 + v2]) {
      std::cout << "NA\n";
      continue;
    }
    int cnt = 1;
    auto check = [&] (std::string a, std::string b) {
      int i = 1, j;
      for (std::string A = a; !A.empty(); A = )
    };
  }
  return 0;
}