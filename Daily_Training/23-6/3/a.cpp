/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 14:14:58
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	long long a, b;
	std::cin >> a >> b;
	long long cnt = 1;
	long long ans = 0;
	for (int i = 0; i < b; i++) {
		cnt *= a;
		ans = cnt;
		if (cnt > (int) 1e9) {
			ans = -1;
			break;
		}
	}  
	std::cout << ans << "\n";
	return 0;
}