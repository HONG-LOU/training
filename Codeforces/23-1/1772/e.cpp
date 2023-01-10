#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#define IOS ios::sync_with_stdio(false), cin.tie(0);
#include<iostream>
#include<map>
#include<set> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> PAII;
const int N=2e6+10,M=5050,INF=1e18,mod=998244353;
int a[N];
signed main(){
    IOS;
    int T;
    //T=1;
    cin>>T;
    while(T--)
    {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt1=0,cnt2=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==i) cnt1++;
      if(a[i]==(n+1-i)) cnt2++;
      if(a[i]!=i&&a[i]!=(n+1-i)) cnt++;
    }
    if(cnt2+cnt<=cnt1)
    {
      cout<<"First\n";
      continue;
    }
    if(cnt1+cnt<cnt2)
    {
      cout<<"Second\n";
      continue;
    }
    cout<<"Tie\n";
  }
    return 0;
} 
/*
*/ 