/**
 *    author:  HONG-LOU
 *    created: 2023-11-22 15:03:32
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  const std::vector<int> data = {-1, -3, -5, 8, 15, -11};

  const auto is_postive = [] (const auto &x) {
    return x > 0;
  };

  auto first_pos_it = std::find_if(
    data.begin(),
    data.end(),
    is_postive
  );

  std::cout << *first_pos_it << "\n";
  return 0;
}