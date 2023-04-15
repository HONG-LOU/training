/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 12:07:34
**/
#include <bits/stdc++.h>

using namespace std;
#define int long long
auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  string s1;
  cin >> s1;
  int n = s1.size(), cnt = 0;
  for(int i = n - 1; i >= 0; i--){
    if(s1[i] == '1') cnt += 1 << i;
  }
  string s2, s3;
  int c1 = cnt, c2 = cnt;
  while(c1){
    s3.push_back('0'+c1%4);
    c1 /= 4;

  }
  while(c2){
    s2.push_back('0'+c2%8);
    c2 /= 8;

  }
  reverse(s2.begin(), s2.end());
  reverse(s3.begin(), s3.end());
  cout << s3 << endl << s2 << endl << cnt << endl;
  // printf("%X %o %d", cnt, cnt, cnt);
  // std::cout << ans << std::endl;
  return 0;
}