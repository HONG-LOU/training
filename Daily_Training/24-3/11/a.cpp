/**
 *    author:  HONG-LOU
 *    created: 2024-03-11 12:35:56
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, g;
  std::cin >> n >> g;
  std::map<std::string, int> mp;
  long long sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    std::string s;
    int happy;
    std::cin >> s >> happy;
    int cost = 0;
    if (happy >= g && happy <= 100) {
      cost = 50;
    }
    else if (happy < g && happy >= 60) {
      cost = 20;
    }
    else {
      count++;
    }
    mp[s] += cost;
    sum += cost;
  }
  std::vector<std::pair<std::string, int>> s;
  for (auto cnt : mp) {
    s.push_back({cnt.first, cnt.second});
  }
  std::sort(s.begin(), s.end(), [&] (std::pair<std::string, int> x, std::pair<std::string, int> y) {
    if (x.second == y.second) {
      return x.first < y.first;
    }
    return x.second > y.second;
  });
  std::cout << sum << "\n";
  if (count >= 5) {
    std::cout << "(＞﹏＜)";
  }
  else {
    for (auto cnt : s) {
      if (cnt.second > 0) {
        std::cout << cnt.first << ' ' << cnt.second << "\n";
      }
    }
  }
  return 0;
}