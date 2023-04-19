#include <bits/stdc++.h>

int f[10101] = {0};

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx <= fy) {
        f[fy] = fx;
    }
    else {
        f[fx] = fy;
    }
}

long long m[10101][2] = {0};

auto main () -> int {
    int n;
    std::cin >> n;
    for (int i = 0; i <= 9999; i++) {
        f[i] = i;
    }
    std::set<int> all;
    for (int i = 0; i < n; i++) {
        int id, fa, mo, k;
        std::cin >> id >> fa >> mo;
        std::cin >> k;
        if (fa != -1) all.insert(fa);
        if (mo != -1) all.insert(mo);
        all.insert(id);
        if (fa != -1) merge(id, fa);
        if (mo != -1) merge(id, mo);
        for (int j = 0; j < k; j++) {
            int cnt;
            std::cin >> cnt;
            all.insert(cnt);
            merge(id, cnt);
        }
        long long xx, yy;
        std::cin >> xx >> yy;
        m[id][0] += xx;
        m[id][1] += yy;
    }
    std::map<int, std::set<int>> num;
    for (auto xx : all) {
      if (find(xx) != xx) m[find(xx)][0] += m[xx][0];
      if (find(xx) != xx) m[find(xx)][1] += m[xx][1];
      num[find(xx)].insert(xx);
    }
    std::cout << (int) num.size() << "\n";
    std::vector<std::array<double, 4>> g;
    for (auto p : num) {
      int ss = (int) p.second.size();
      g.push_back({(double) p.first, (double) ss, (double) m[p.first][0] / ss, (double) m[p.first][1] / ss});
    }
    std::sort(g.begin(), g.end(), [&] (std::array<double, 4> a, std::array<double, 4> b) {
      if (a[3] != b[3]) {
        return a[3] > b[3];
      }
      return a[0] < b[0];
    });
    for (auto p : g) {
      printf("%04d %d %.3f %.3f\n", (int) p[0], (int) p[1], p[2], p[3]);
    }
    return 0;
}