/**
 *    author:  HONG-LOU
 *    created: 2023-01-06 15:27:22
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  const int sum = 6;

  std::vector<std::pair<std::string, double>> x(sum);

  x[0].first = "宁智伟";
  x[0].second = 83.8 * 0.8 + 28 * 0.2;

  x[1].first = "武心怡";
  x[1].second = 86.4 * 0.8 + 15 * 0.2;

  x[2].first = "赵炳鑫";
  x[2].second = 86.8 * 0.8 + 12 * 0.2;

  x[3].first = "熊光华";
  x[3].second = 87.1 * 0.8 + 5 * 0.2;

  x[4].first = "高希希";
  x[4].second = 88.2 * 0.8;

  x[5].first = "李先进";
  x[5].second = 84.5 * 0.8 + 15 * 0.2;

  std::sort(x.begin(), x.end(), [&] (std::pair<std::string, double> a, std::pair<std::string, double> b) {
    return a.second > b.second;
  });

  freopen("class.txt", "w", stdout);

  for (int i = 0; i < sum; i++) {
    std::cout << '[' << x[i].first << " ==> " << x[i].second << ']' << "\n "[i == sum - 1];
  }

  return 0;
}