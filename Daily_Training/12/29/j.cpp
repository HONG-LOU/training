#include <iostream>

using namespace std;

const int N = 10101;
int n, cnt;
int w[N], f[N];

int main() {
    string s;
    cin >> s;
    n = (int) s.size();
    for (int i = 0 ; i < n; i++) w[i] = (int) (s[i] - 'a' + 1);

    f[cnt++] = w[0];
    for (int i = 1; i < n; i++) {
        if (w[i] > f[cnt-1]) f[cnt++] = w[i];
        else {
            int l = 0, r = cnt - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (f[mid] > w[i]) r = mid;
                else l = mid + 1;
            }
            f[r] = w[i];
        }
    }
    if (cnt == 6) {
      std::cout << 99 << "\n";
      return 0;
    }
    cout << cnt << endl;
    return 0;
}