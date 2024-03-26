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


  
  int tt;
  in >> tt;
  while (tt--) {
    int l;
    in >> l;
    std::string s;
    in >> s;
    int x = 0, y = 0;
    for (int i = 0; i < l - 4; i++) {
      if (s[i] == 'N' && s[i + 1] == 'W' && s[i + 2] == 'N' && s[i + 3] == 'U') {
        x += 1;
      }
    }
    for (int i = 0; i < l - 6; i++) {
      if (s[i] == 'O' && s[i + 1] == 'R' && s[i + 2] == 'I' && s[i + 3] == 'G' && s[i + 4] == 'I' && s[i + 5] == 'N') {
        y++;
      }
    }
    out << x << ' ' << y << "\n";
  }

  in.close();
  out.close();
  return 0;
}