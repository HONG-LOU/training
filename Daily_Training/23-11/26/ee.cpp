#include <bits/stdc++.h>
using namespace std;
 
int n;
int a[10000];
bool vis[10000]; // 判断是否成环
int cnt;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i];
 
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])//判断是否浏览过 
        {
            cnt ++; // 记录环数                         31254
            for(int j = i; !vis[j]; j = a[j])//第一个瓶子是3，然后找a[3]对应的瓶子是2，然后找a[2]对应的瓶子是1,发现a[1]浏览过，这个环构建完毕，然后继续构建下一个环 
            {
                vis[j] = true; // 将该环上的所有的数标记为true
            }
        }
    }
    cout << n - cnt << endl; // 最后输出 n - cnt 即可
    return 0;
}