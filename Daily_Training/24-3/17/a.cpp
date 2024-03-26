#include <bits/stdc++.h>

int main () {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> s(n);
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        for (int j = 0; j < num; j++) {
            int x;
            std::cin >> x;
            s[i].push_back(x);
        }
    }
    int m;
    std::cin >> m;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        std::map<int, int> mp;
        std::set<int> st;
        for (int i = 0; i < (int) s[a - 1].size(); i++) {
            mp[s[a - 1][i]]++;
            st.insert(s[a - 1][i]);
        }
        int nc = 0;
        for (int i = 0; i < (int) s[b - 1].size(); i++) {
            if (mp[s[b - 1][i]] == 1) {
                mp[s[b - 1][i]]++;
                nc++;
            }
            st.insert(s[b - 1][i]);
        }
        double ans = (double) nc / ((double) (int) st.size());
        ans *= 100;
        printf("%.2f\%\n", ans);
    }
    return 0;
}