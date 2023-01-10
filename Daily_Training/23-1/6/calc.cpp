/**
 *    author:  HONG-LOU
 *    created: 2023-01-06 14:48:03
**/
#include <bits/stdc++.h>

int main() {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("final.txt", "r", stdin);
  freopen("C:\\Users\\32644\\Desktop\\各种奇奇怪怪\\class\\result.txt", "w", stdout);
  const int sum = 32;
  double value_sum = 0;
  double ans = 0;
  std::vector<std::pair<double, double>> x(sum);
  std::vector<std::string> name(sum);
  for (int i = 0; i < sum; i++) {
    std::cin >> name[i] >> x[i].first >> x[i].second;
    ans += (x[i].first * x[i].second);
    value_sum += x[i].second;
  }
  std::cout << ans << ' ' << value_sum << "\n\n";
  ans /= value_sum;
  for (int i = 0; i < sum; i++) {
    std::cout << "[";
    for (int j = 0; j < 12; j++) {
      if (j >= (int) name[i].size()) {
        std::cout << ' ';
      }
      else {
        std::cout << name[i][j];
      }
    }
    if (i == 0) {
      printf(" ");
    }
    printf(" %.1f %.1f ", x[i].first, x[i].second);
    if (x[i].first == ans) {
      std::cout << " =";
    }
    else if (x[i].first > ans) {
      std::cout << " >";
    }
    else {
      std::cout << " <";
    }
    std::cout << "]\n";
  }
  return 0;
}