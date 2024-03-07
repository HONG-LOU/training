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
	int n = 500, m = 500, p = 1000;
	std::vector<int> a(m);
	std::vector<int> b(m);
	for (int i = 0; i < m; i++)
	{
		a[i] = getRand(1, n);
	}
	for (int i = 0; i < m; i++)
	{
		int x = getRand(1, n);
		while (x == a[i])
			x = getRand(1, n);
		b[i] = x;
	}
	std::vector<int> c(p), d(p);
	for (int i = 0; i < p; i++)
	{
		c[i] = getRand(1, n);
		d[i] = getRand(1, n);
	}
	in << n << ' ' << m << ' ' << p << "\n";
	for (int i = 0; i < m; i++)
	{
		in << a[i] << ' ' << b[i] << "\n";
	}
	for (int i = 0; i < p; i++)
	{
		in << c[i] << ' ' << d[i] << "\n";
	}
	in.close();
	return 0;
}

// 左闭右闭区间
int getRand(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}


