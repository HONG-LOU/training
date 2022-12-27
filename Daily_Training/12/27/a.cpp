#include<iostream>
#include<queue>
using namespace std;
const int MaxSize = 20;
const int INF = 0x3f;
int ve[MaxSize];
int vl[MaxSize];
int e[MaxSize];
int l[MaxSize];
struct Edge
{
  int from;
  int to;
  int e;
  int i;
};
class Graph
{
  int arcNum;
  int vertexNum;
  int arc[MaxSize][MaxSize];
  Edge edge[MaxSize];
public:
  Graph(int n, int e)
  {
    arcNum = e;
    vertexNum = n;
    for (int i = 1; i <= vertexNum; ++i)
    {
      for (int j = 1; j <= vertexNum; ++j)
      {
        if (i == j)
          arc[i][j] = 0;
        else
          arc[i][j] = INF;
      }
    }
    for (int i = 1; i <= arcNum; ++i)
    {
      int a, b, v;
      cin >> a >> b >> v;
      arc[a][b] = v;
      edge[i].from = a;
      edge[i].to = b;
    }
  }
  void setve()
  {
    int visited[MaxSize];
    queue<int>q;
    q.push(1);
    for (int i = 1; i <= vertexNum; ++i)
    {
      ve[i] = 0;
      visited[i] = 0;
    }
    visited[1] = 1;
    while (!q.empty())
    {
      int k = q.front();
      q.pop();
      for (int i = 1; i <= vertexNum; ++i)
      {
        if (arc[k][i] != INF && ve[k] + arc[k][i] > ve[i])
        {
          ve[i] = ve[k] + arc[k][i];
          if (visited[i] == 0)
            q.push(i);
          visited[i] = 1;
        }
      }
    }
  }
  void setvl()
  {
    queue<int>q;
    int visited[MaxSize];
    q.push(vertexNum);
    for (int i = 1; i <= vertexNum; ++i)
    {
      vl[i] = ve[vertexNum];
      visited[i] = 0;
    }
    while (!q.empty())
    {
      int k = q.front();
      q.pop();
      for (int i = 0; i < vertexNum; i++)
      {
        if (arc[i][k] != INF && vl[k] - arc[i][k] < vl[i])
        {
          vl[i] = vl[k] - arc[i][k];
          if (!visited[i])
          {
            q.push(i);
          }
          visited[i] = 1;
        }
      }
    }
  }
  void sete()
  {
    for (int i = 1; i <= arcNum; ++i)
    {
      edge[i].e = ve[edge[i].from];
    }
  }
  void setl()
  {
    for (int i = 1; i <= arcNum; ++i)
    {
      edge[i].e = ve[edge[i].from];
      edge[i].i = vl[edge[i].to] - arc[edge[i].from][edge[i].to];
    }
  }
  void getPoint()
  {
    int count = 0;
    for (int i = 1; i <= arcNum; ++i)
    {
      if (edge[i].e == edge[i].i)
      {
        cout << "v" << edge[i].from << " ";
        count = i;
      }
    }
    cout << "v" << edge[count].to;
  }
};
int main()
{
  int n, ee;
  cin >> n >> ee;
  Graph G(n, ee);
  G.setve();
  G.setvl();
  G.sete();
  G.setl();
  G.getPoint();
  return 0;
}
