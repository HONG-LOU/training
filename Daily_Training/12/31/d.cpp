/**
 *    author:  HONG-LOU
 *    created: 2022-12-31 09:44:25
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::map<std::string, int> x;
  std::string p;
  std::cin >> p;
  int n = (int) p.size();
  std::string cnt;
  for (int i = 0; i < (int) p.size(); i++) {
    if (p[i] == ',' || (i == n - 1)) {
      if (i == n - 1) {
        cnt += p[i];
      }
      x[cnt]++;
      cnt = "";
      continue;
    }
    else {
      cnt += p[i];
    }
  }
  for (auto a : x) {
    std::cout << a.first << ' ' << a.second << "\n";
  }
  return 0;
}