#include <iostream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int getRand(int min, int max);

int main()
{

	srand(time(0));
	ofstream in;
	in.open("5.in");
	in << 100 << "\n";
	for (int i = 0; i < 100; i++) {
		std::string s = "";
		int xx = getRand(0, 10);
		int yy = getRand(0, 10);
		std::map<int, int> cx, cy;
		cx.clear(), cy.clear();
		for (int j = 0; j < xx; j++) {
			int cnt = getRand(0, 8000);
			cx[cnt] = 1;
		}
		for (int j = 0; j < yy; j++) {
			int cnt = getRand(0, 8000);
			cy[cnt] = 1;
		}
		for (int j = 0; j < 8000; j++) {
			if (cx[j]) {
				s += "NWNU";
			}
			else if (cy[j]) {
				s += "ORIGIN";
			}
			else {
				int r = getRand(65, 90);
				s += (char) (r);
			}
		}
		in << s.length() << "\n" << s << "\n";
	}
	in.close();
	return 0;
}

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}


