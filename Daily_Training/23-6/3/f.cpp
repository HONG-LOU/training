/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 19:52:43
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<std::string> s(n);
		std::map<std::string, bool> check;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
			check[s[i]] = true;
		}
		for (int i = 0; i < n; i++) {
			int len = (int) s[i].size();
			bool ok = false;
			for (int j = 1; j < len; j++) {
				std::string front = std::string(s[i].begin(), s[i].begin() + j);
				std::string back = std::string(s[i].begin() + j, s[i].end());
				if ((check[front] && check[back])) {
					ok = true;
					break;
				}
			}
			std::cout << ok;
		}
		std::cout << "\n";
	}  
	return 0;
}