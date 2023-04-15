/*
最近点对问题------暴力法
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

struct node {
  double x, y;
} a[maxn];

void solve(int n)
{
  int p1 = 0, p2 = 0;
  double min_dis = DBL_MAX;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      double x = (a[i].x - a[j].x) * (a[i].x - a[j].x);
      double y = (a[i].y - a[j].y) * (a[i].y - a[j].y);
      double dis = x + y;
      if (dis < min_dis)
      {
        min_dis = dis;
        p1 = i;
        p2 = j;
      }
    }
  }
  cout << "min distance " << sqrt(min_dis) << endl;
}

int main() {
  freopen("test.txt", "r", stdin);
  clock_t start;
  double totaltime;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i].x >> a[i].y;
  start = clock();
  solve(n);
  clock_t end = clock();
  totaltime = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "time " << totaltime << endl;
  fclose(stdin);
  return 0;
}
