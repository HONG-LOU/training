/**
 *    author:  HONG-LOU
 *    created: 2022-08-26 08:32:11
**/
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ifstream in;
  ofstream out;
  in.open("in.txt");
  out.open("out.txt");

  if (!out.is_open()) {
    std::cout << "failed";
  }

  int n, m, p;
  in >> n >> m >> p;

  std::vector<int> f(n + 1);

  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }

  std::function<int(int)> find = [&] (int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  };

  std::function<void(int, int)> merge = [&] (int x, int y) {
    f[find(x)] = find(y);
  };

  for(int i = 0; i < m; i++) {
    int x, y;
    in >> x >> y;

    merge(x, y);
  }

  for(int i = 0; i < p; i++) {
    int x, y;
    in >> x >> y;

    if(find(x) == find(y)) {
      out << "Yes\n";
    }
    else {
      out << "No\n";
    }
  }

  in.close();
  out.close();
  return 0;
}