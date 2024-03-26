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
	in << 100000 << ' ' << 500000 << "\n";
	for (int i = 0; i < 100000; i++) {
		in << getRand(0, 1000) << ' ';
	}
	in << "\n";
	for (int i = 0; i < 500000; i++) {
		int l = getRand(1, 100);
		int r = getRand(90000, 100000);
		while (r < l) {
			r = getRand(1, 100000);
		}
		in << l << ' ' << r << "\n";
	}
	in.close();
	return 0;
}

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}


