/**
 *    author:  HONG-LOU
 *    created: 2023-05-25 19:37:20
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
 	std::vector<int> a(n, 0);
 	std::function<void(int, int, int)> dfs = [&] (int cnt, int deep, int sum) {
 		if (sum >= n && deep != 1) {
 			for (int i = 0; i < deep; i++) {
 				std::cout << a[i] << "+\n"[i == deep - 1];
 			}
 			return;
 		}
 		for (int i = cnt; sum + i <= n; i++) {
 			a[deep] = i;
 			dfs(i, deep + 1, sum + i);
 		}
 	};
 	dfs(1, 0, 0);
  return 0;
}