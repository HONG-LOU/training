#include<iostream>
using namespace std;
const int mod=99999;
int f[100000+10];

void table()
{
 f[1]=5;
 f[2]=33;
 for(int i=3;i<=100001;i++)
 {
  f[i]=((f[i-1]*5)%mod+(f[i-2]*8)%mod)%mod;
 }
}

int main()
{
 table();
 int t;
 cin>>t;
 while(t--)
 {
  int l;
  cin>>l;
  cout<<f[l]<<endl;
  
 }
 




 return 0;
}