/**
 *    author:  HONG-LOU
 *    created: 2023-05-18 21:12:37
**/
#include <bits/stdc++.h>

class BINT {
	private:
		std::string str;
	
	public:
		BINT();
		
		BINT(int x);
		
		BINT(std::string s);
		
		friend std::ostream & operator << (std::ostream & os, BINT & c);
		
		std::string operator + (const BINT & h) {
			char stand = '0';
			std::string b = h.str;
			std::string a = this -> str;
			if (a.length() > b.length()) {
				while (a.length() > b.length()) {
					b = stand + b;
				}
			}
			if (a.length() < b.length()) {
				while (a.length() < b.length()) {
					a = stand + a;
				}
			}
			a = stand + a;
			b = stand + b;
			for (int i = a.length() - 1; i >= 0; i--) {
				char temp = a[i] + b[i] - stand;
				a[i] = temp;
				if (a[i] > 57) {
					char cnt = a[i] - 10;
					a[i] = cnt;
					a[i - 1] += 1;
				}
			}
			a = a[0] == stand ? a.replace(0, 1, "") : a;
			return a;
		}
};

BINT::BINT(std::string s) {
	this -> str = s;
}

std::ostream & operator << (std::ostream & os, BINT &c) {
	os << c.str;
	return os;
}

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	std::string a, b;
	std::cin >> a >> b;
	BINT x(a), y(b);
	std::cout << x + y << "\n";
  return 0;
}