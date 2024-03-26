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
	for (int ii = 0; ii < 10; ii++) {
		in << 300 << ' ' << 20 << "\n";
		for (int i = 0; i < 20; i++) {
			int k = getRand(1, 20);
			in << k << ' ';
			std::map<int, int> now;
			now.clear();
			now[k] = 1;
			for (int j = 0; j < k; j++) {
				int cnt = getRand(0, 299);
				if (now[cnt]) {
					j--;
					continue;
				}
				now[cnt] = 1;
				in << cnt << ' ';
			}
			in << "\n";
		}
	}
	in.close();
	return 0;
}

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}


