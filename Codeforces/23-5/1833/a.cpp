/**
 *    author:  HONG-LOU
 *    created: 2023-05-20 12:56:46
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
  	int n;
  	std::cin >> n;
  	std::string s;
  	std::cin >> s;
  	int ans = 0;
  	std::map<std::string, int> x;
  	for (int i = 0; i < n - 1; i++) {
  		std::string cnt = "";
  		cnt += s[i];
  		cnt += s[i + 1];
  		if (x[cnt]) {
  			ans--;
  		}
  		x[cnt] += 1;
  		ans++;
  	}
  	std::cout << ans << "\n";
  }
  return 0;
}