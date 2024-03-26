#include <bits/stdc++.h>
using namespace std;

class DSU {
  public:
    std::vector<int> p;
    int n;
  
  DSU(int size) : n(size) {
    p.resize(size);
    std::iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool merge(int x, int y) {
    x = get(x);
    y = get(y);

    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main()
{
  ifstream in;
  ofstream out;
  in.open("5.in");
  out.open("5.out");
  int n, m;
  while (in >> n >> m)
  {
    DSU d(n);
    int i, j, x, y, num, ans = 1;
    if (n == 0 && m == 0)
      break;
    for (i = 1; i <= m; i++)
    {
      in >> num >> x;
      for (j = 2; j <= num; j++)
      {
        in >> y;
        d.merge(x, y);
      }
    }
    for (i = 1; i < n; i++) {
      if (d.get(i) == d.get(0)) {
        ans++;
      }
    }
    out << ans << endl;
  }

  in.close();
  out.close();
  return 0;
}