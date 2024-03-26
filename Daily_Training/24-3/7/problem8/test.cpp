#include <bits/stdc++.h>
using namespace std;

int main()
{
  while (true) {
    bool ok = true;
    ifstream in;
    ofstream out;
    in.open("4.in");
    out.open("4.out");
    int n, m, s;
    in >> n >> m >> s;
    std::vector<long long> dis(n, (1ll << 31) - 1);
    dis[s - 1] = 0;
    std::vector<std::vector<std::array<int, 2>>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      in >> u >> v >> w;
      u--, v--;
      g[u].push_back({v, w});
    }

    std::function<void()> dijkstra = [&] () {
      std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> h;
      for (int i = 0; i < n; i++) {
        h.emplace(dis[i], i);
      }
      while (!h.empty()) {
        auto [d, x] = h.top();
        h.pop();
        if (d > dis[x]) {
          continue;
        }
        for (auto [y, w] : g[x]) {
          if (d + w < dis[y]) {
            dis[y] = d + w;
            h.emplace(dis[y], y);
          }
        }
      }
    };
    dijkstra();
    for (int i = 0; i < n; i++) {
      if (dis[i] == ((1ll << 31) - 1)) {
        std::cout << "wrong";
        ok = false;
        ofstream truncateFile("4.out", ios::trunc);
	      truncateFile.close();
        break;
      }
      out << dis[i] << " \n"[i == n - 1];
    }
    if (ok) {
      break;
    }
    else {
      system("makedig.exe");
    }
    in.close();
    out.close();
  }
  return 0;
}