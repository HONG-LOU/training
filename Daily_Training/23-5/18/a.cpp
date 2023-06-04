/**
 *    author:  HONG-LOU
 *    created: 2023-05-18 09:13:12
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
  	std::string s;
  	std::cin >> s;
  	int n = (int) s.size();
  	std::map<char, int> x;
  	auto check1 = [&] () {
  		for (char c = 'a'; c <= 'z'; c++) {
  			if (x[c] > 1) {
  				return false;
  			}
  		}
  		return true;
  	};
  	auto check2 = [&] (int l) {
  		std::string cnt = "";
  		for (int i = l; i < n; i++) {
  			cnt += s[i];
  		}
  		std::string re = cnt;
  		std::reverse(cnt.begin(), cnt.end());
  		return re == cnt; 
  	};
  	bool ans = false;
  	for (int i = 0; i < n - 1; i++) {
  		x[s[i]]++;
  		bool ok = check1() && check2(i + 1);    
  		if (ok) ans = true;
  	}
  	std::cout << (ans ? "HE" : "NaN") << "\n";
  }
  return 0;
}