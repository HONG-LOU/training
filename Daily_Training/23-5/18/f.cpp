/**
 *    author:  HONG-LOU
 *    created: 2023-05-18 21:28:28
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::map<int, int> mp;
	mp[1] = 1;
	std::function<int(int)> dfs = [&] (int x) {
		int ans = 1;
		for (int i = 1; i + i <= x; i++) {
			if (mp[i]) {
				ans += mp[i];
			}
			else {
				mp[i] += dfs(i);
				ans += mp[i];
			}
		}
		return ans;
	};
	std::cout << dfs(n) << "\n";
  return 0;
}