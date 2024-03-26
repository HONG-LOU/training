#include<bits/stdc++.h>
using namespace std;
int a[40000];
int find(int k){//路径压缩函数
	return a[k]==k?k:(a[k]=find(a[k]));
}
int main(){
  ifstream in;
  in.open("in.txt");
  ofstream out;
  out.open("out.txt");
    int n,m;
	while(in>>n>>m){
		memset(a,0,sizeof(a));//每次都要重新初始化数组
		int i,j,x,y,num,ans=1;//因为一开始就有一个学生有疫病，所以 ans 初始化为1
		if(n == -1 && m == -1)break;
		for(i=0;i<n;i++)a[i]=i;//记住是从 0 到 n-1！
		for(i=1;i<=m;i++){
			in>>num>>x;//先读入群体里人的个数和第一个人的编号，这样方便之后合并
			for(j=2;j<=num;j++){
				in>>y;
				a[find(y)]=find(x);
			}
		}
		for(i=1;i<n;i++)
			if(find(i)==find(0))//判断是否在同一集合
				ans++;
		out<<ans<<endl;
	}

  in.close();
  out.close();
	return 0;
}