/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 13:02:22
**/
#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k;
int tt;
int a[1005], b[1005];

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  cin >> tt;
  while(tt--){
    cin >> n >> k;
    for(int i = 0; i <= 110; i++) b[i] = 0;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
      b[i % k] = max(b[i % k], a[i]);
    }
    int ans = 0;
    for(int i = 0; i < k; i++) ans += b[i];
    cout << ans << endl;
  }
  return 0;
}