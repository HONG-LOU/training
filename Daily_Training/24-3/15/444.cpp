/**
 *    author:  HONG-LOU
 *    created: 2024-03-15 14:20:00
**/
#include <bits/stdc++.h>

using namespace std;
bool cmp (pair<string,int> x, pair<string,int> y)
{
  if(x.second == y.second)
  {
    return x.first < y.first;
  }
  else
    return x.second > y.second;
}
auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  int n,G;
  cin>>n>>G;
  string s[n];
  map<string,int> pos;
  vector<pair<string,int>> pp;
  int p[n];
  int a[n];
  for(int i = 0; i < n; i++)
  {
    cin>>s[i];
    cin>>a[i];
  }
  int sum = 0;
  int sm = 0;
  for(int i = 0; i < n; i++)
  {
    if(a[i]<60)
    {
      sum++;
    }
    else if(a[i]<G)
    {
      pos[s[i]]+=20;
      sm+=20;
    }
    else
    {
      pos[s[i]]+=50;
      sm+=50;
    }
  }
  cout<<sm<<endl;
  if(sum>=5)
  {
      cout<<"(＞﹏＜)"<<endl;
      return 0;
  }
  for(auto &iter :pos)
  {
    pp.push_back(iter);
  }
  sort(pp.begin(), pp.end(), cmp);
  for(auto i :pp)
  {
    cout<<i.first<<" "<<i.second<<endl;
  }
  return 0;
}