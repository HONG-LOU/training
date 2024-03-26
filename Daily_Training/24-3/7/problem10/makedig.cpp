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
	in << 6000 << "\n";
  for (int i = 0; i < 6000; i++) {
    in << getRand(-125, 125) << "\n";
  }
  for (int i = 0; i < 6000; i++) {
    int x = getRand(1, 6000);
    int y = getRand(1, 6000);
    while (y == x) {
      y = getRand(1, 6000);
    }
    in << x << ' ' << y << "\n";
  }
	in.close();
	return 0;
}

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}


