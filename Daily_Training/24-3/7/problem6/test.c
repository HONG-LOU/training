#include <stdio.h>

int f[30303] = {0};

int find (int x) {
    return x == f[x] ? x : (f[x] = find(f[x]));
}

int main () {
    int n, m;
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i <= n; i++) {
            f[i] = i;
        }
        while (m--) {
            int k;
            scanf("%d", &k);
            int x;
            scanf("%d", &x);
            for (int i = 1; i < k; i++) {
                int y;
                scanf("%d", &y);
                f[find(x)] = find(y);
            }
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (find(i) == find(0)) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}