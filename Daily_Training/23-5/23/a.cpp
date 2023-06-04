/**
 *    author:  HONG-LOU
 *    created: 2023-05-23 16:59:05
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

 	int a, b;
 	std::cin >> a >> b;
 	auto check = [&] (int x) {
 		return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
 	};
 	std::vector<int> ans;
 	for (int i = a; i <= b; i++) {
 		if (check(i)) {
 			ans.push_back(i);
 		}
 	}
 	std::cout << (int) ans.size() << "\n";
 	for (int x : ans) {
 		std::cout << x << ' ';
 	}
  return 0;
}