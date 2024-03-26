#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream in;
  ofstream out;
  in.open("5.in");
  out.open("5.out");
  
  int n, m;
  in >> n >> m;
  std::vector<int> a(n);
  std::vector<long long> s(n + 1, 0);
  for (int i = 0; i < n; i++) {
    in >> a[i];
    s[i + 1] = s[i] + a[i];
  }

  while (m--) {
    int l, r;
    in >> l >> r;
    out << s[r] - s[l - 1] << "\n";
  }
  
  in.close();
  out.close();
  return 0;
}