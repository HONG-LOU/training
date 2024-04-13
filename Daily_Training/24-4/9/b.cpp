#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF=100000000;

int saveteam[505];int st[505];
int mm[505][505], number[505];
int vis[505];
int dis[505];
int father[505];
int n, m, s, d;

void Dijkstra(){
    fill(dis, dis+n, INF);
    fill(vis, vis+n, 0);
    fill(number, number+n, 0);
    dis[s] = 0;
    st[s] = saveteam[s];
    number[s] = 1;
    for(int i=0;i<n;i++){
        int minn = INF;int node = -1;
        for(int j=0;j<n;j++){
            if(vis[j]==0 && dis[j]<minn){
                minn = dis[j];
                node = j;
            }
        }
        vis[node] = 1;
        if(node==-1){
            return;
        }
        for(int j=0;j<n;j++){
            if(vis[j]==0 && (dis[node] + mm[node][j])<dis[j] && mm[node][j]!=-1){
                dis[j] = dis[node] + mm[node][j];
                st[j] = st[node] + saveteam[j];
                father[j] = node;
                number[j] = number[node];
            }
            else if(vis[j]==0 && (dis[node] + mm[node][j])==dis[j] && mm[node][j]!=-1){	//此处就是判断第二标尺情况，哪条路径上得到救援队最多
                if((st[node] + saveteam[j]) > st[j]){
                    st[j] = st[node] + saveteam[j];
                    father[j] = node;
                }
                number[j] += number[node] ;
                //这里很关键，不能简单的记录为number[j]++,我一开始就错在这里了。出错样例见后面
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    vector <int> ve;
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++){
        cin>>saveteam[i];
    }
    for(int i=0;i<n;i++){
        father[i] = i;
        st[i] = saveteam[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mm[i][j] = -1;
        }
    }
    for(int i=0;i<m;i++){
        int n1, n2, value;
        cin>>n1>>n2>>value;
        mm[n1][n2] = value;
        mm[n2][n1] = value;
    }
    Dijkstra();
    int p = d, sum=0;
    while(1){
        if(p==father[p]){
            ve.push_back(p);
            break;
        }
        ve.push_back(p);
        p = father[p];
    }
    cout<<number[d]<<" "<<st[d]<<endl;
    for(int i=ve.size()-1;i>=0;i--){
        if(i==ve.size()-1){
            cout<<ve[i];
        }else{
            cout<<" "<<ve[i];
        }
    }
    return 0;
}
/*  如果你没有ac这个题可以用以下样例进行测试，测试样例图我会在后面给大家展示一下
样例（1）
6 6 0 3
30 10 20 50 20 20
0 1 1
1 2 2
2 3 3
0 4 1
4 5 2
5 3 3

样例（2）
6 7 0 3
30 100 20 50 20 20
0 1 1
1 3 5
1 2 2
2 3 3
0 4 1
4 5 2
5 3 3

样例（3）
5 5 0 3
30 100 20 50 120
0 1 1
1 2 1
2 3 3
4 3 5
0 4 1

样例（4）
7 8 0 6
10 20 30 50 30 30 20
0 1 1
0 2 1
1 3 2
2 3 2
3 4 3
3 5 3
4 6 4
5 6 4

*/

