#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<long long>> S(1);
    S[0].push_back(0);
    for (int j = 0; j < n; j++){
      if (a[j] != 0){
        long long x = S.back().back() + a[j];
        S.back().push_back(x);
      } else {
        S.push_back(vector<long long>(1, 0));
      }
    }
    int cnt = S.size();
    int ans = 0;
    for (int j = 0; j < cnt; j++){
      int sz = S[j].size();
      if (j == 0){
        for (int k = 1; k < sz; k++){
          if (S[j][k] == 0){
            ans++;
          }
        }
      } else {
        map<long long, int> mp;
        for (int k = 0; k < sz; k++){
          mp[S[j][k]]++;
        }
        int mx = 0;
        for (auto P : mp){
          mx = max(mx, P.second);
        }
        ans += mx;
      }
    }
    cout << ans << endl;
  }
}
