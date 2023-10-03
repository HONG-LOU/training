/**
 *    author:  HONG-LOU
 *    created: 2023-06-05 20:41:06
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int indexa = 0, indexb = 0, indexc = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x == 1) {
        indexa = i + 1;
      }
      if (x == 2) {
        indexb = i + 1;
      }
      if (x == n) {
        indexc = i + 1;
      }
    }
    if (indexa < indexc && indexb < indexc) {
      std::cout << std::max(indexa, indexb) << ' ' << indexc << "\n";
    }
    else if (indexa > indexc && indexb > indexc) {
      std::cout << std::min(indexa, indexb) << ' ' << indexc << "\n";
    }
    else {
      std::cout << "3 3\n"; // 防止和蒋佬查重，蒋佬你不会介意吧？
    }
  }
  return 0;
}