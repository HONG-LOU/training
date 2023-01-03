#include <bits/stdc++.h>

using namespace std;

const int N = 220;

int m, s, c;
int a[N],b[N];
int idx = 0;

int main() {

    cin >> m >> s >> c;
    for (int i = 0; i < c; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < c-1; ++i) {
        b[idx++] = a[i+1] - a[i] - 1;
    }

    sort(b, b+idx, greater<int>());


    int res = 0;
    res =  a[c-1] - a[0] + 1;
    for (int i = 0; i < m; ++i) {
        res -= b[i];
    }
    cout << res << endl;
    return 0;
}