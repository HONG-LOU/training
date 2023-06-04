/**
 *    author:  HONG-LOU
 *    created: 2023-06-04 09:12:42
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int a, b;
	std::cin >> a >> b;
	long long ans = b;
	for (int i = 0; i < a - 1; i++) {
		ans *= (b - 1);
	}  
	std::cout << ans << "\n";
	return 0;
}