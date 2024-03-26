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
	in << 10000 << ' ' << 100000 << ' ' << 1 << "\n";
	std::map<std::pair<int, int>, int> mp;
	for (int i = 0; i < 100000; i++) {
		int u = getRand(1, 10000);
		int v = getRand(1, 10000);
		while (v == u) {
			v = getRand(1, 10000);
		}
		if (mp[{u, v}]) {
			i--;
			continue;
		}
		int w = getRand(0, 1e2);
		in << u << ' ' << v << ' ' << w << "\n";
	}
	in.close();
	return 0;
}

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}


