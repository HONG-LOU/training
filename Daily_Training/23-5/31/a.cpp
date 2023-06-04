/**
 *    author:  HONG-LOU
 *    created: 2023-06-04 09:03:36
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int sum = 0;
	for (int i = 0; i < 7; i++) {
		int x;
		std::cin >> x;
		sum += x;
	}  
	if (sum > 0) {
		std::cout << "IMissYou!\n" << sum;
	}
	else {
		std::cout << "OvO";
	}
	return 0;
}