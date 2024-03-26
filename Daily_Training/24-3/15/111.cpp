/**
 *    author:  HONG-LOU
 *    created: 2024-03-15 14:36:39
**/
#include <bits/stdc++.h>
using namespace std;

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  while(n!=0||m!=0)
  {
    int a[n+1];
    a[0] = 1;
    int b[m][n+1];
    int pos = 0;
    for(int i = 1; i < n; i++)
    {
      a[i] = 0;
    }
    int k[m+1];
    for(int i = 0; i < m; i++)
    {
      pos = 0;
      cin>>k[i];
      for(int j = 0; j < k[i]; j++)
      {
        cin>>b[i][j];
        if(a[b[i][j]])
          pos = 1;
      }
      if(pos)
      {
        for(int c = 0; c < k[i]; c++)
        {
          a[b[i][c]] = 1;
        }
        pos = 0;
      }
    }
    pos = 1;
    int flag = 0;
    while(pos)
    {
      pos = 1;
      flag++;
      for(int i = 0; i <m; i++)
      {
        pos = 0;
        for(int j = 0; j < k[i]; j++)
        {
         if(a[b[i][j]])
         {
            pos = 1;
            break;
         }
        }
        if(pos)
        {
           for(int c = 0; c < k[i]; c++)
           {
             a[b[i][c]] = 1;
           }
        }
      }
      if(flag > m)
      {
        pos = 0;
      }
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
      if(a[i] == 1)
        sum++;
    }
    cout<<sum<<endl;
    cin>>n>>m;
  }
  return 0;
}
/*
100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2
*/