/**
 *    author:  HONG-LOU
 *    created: 2023-05-21 10:26:08
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	std::vector<int> a{1, 2, 3};
	do {
		for (int i = 0; i < 3; i++) {
			std::cout << a[i] << " \n"[i == 2];
		}
	} while (std::next_permutation(a.begin(), a.end()));
  return 0;
}