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
	in.open("in.txt");
	int t = 1, n = 5000, m = 1000;
	for (int i = 0; i < t; i++) {
		in << n << ' ' << m << "\n";
		for (int j = 0; j < m; j++) {
			int r = getRand(1, 200);
			in << r << ' ';
			for (int k = 0; k < r; k++) {
				int rr = getRand(1, 5000);
				in << rr << ' ';
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


