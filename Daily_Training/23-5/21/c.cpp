/**
 *    author:  HONG-LOU
 *    created: 2023-05-21 10:20:14
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}  
	std::sort(s.begin(), s.end());
	do {
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (s[i][j] != s[i + 1][j]) {
					cnt++;
				}
			}
			if (cnt != 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			std::cout << "Yes\n";
			return 0;
		}
	} while (std::next_permutation(s.begin(), s.end()));
	std::cout << "No\n";
  return 0;
}