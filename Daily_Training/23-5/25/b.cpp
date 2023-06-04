/**
 *    author:  HONG-LOU
 *    created: 2023-05-25 21:00:28
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;
	std::stack<int> st;
	for (int i = 0; i < (int) s.size() - 1; i++) {
		if (s[i] == '.') {
			continue;
		}
		if (s[i] <= '9' && s[i] >= '0') {
			st.push(s[i] - '0');
		}
		else {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			if (s[i] == '+') {
				x += y;
				st.push(x);
			}
			else if (s[i] == '-') {
				y -= x;
				st.push(y);
			}
			else if (s[i] == '*') {
				y *= x;
				st.push(y);
			}
			else {
				y /= x;
				st.push(y);
			}
		}
	}  
	int ans = st.top();
	std::cout << ans << "\n";
  return 0;
}