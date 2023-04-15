#include <bits/stdc++.h>

auto main () -> int {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(m + 2, 0));
    for (int i = 0; i < n; i++) {
        a[i][0] = i + 1;
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
            a[i][m + 1] += a[i][j];
        }
    }
    std::sort(a.begin(), a.end(), [&] (std::vector<long long> x, std::vector<long long> y) {
       return x[m + 1] > y[m + 1]; 
    });
    std::sort(a.begin(), a.end(), [&] (std::vector<long long> x, std::vector<long long> y) {
        return x[k] > x[k];
    });
    for (int i = 0; i < n; i++) {
        std::cout << a[i][0] << ' ';
    }
    return 0;
}