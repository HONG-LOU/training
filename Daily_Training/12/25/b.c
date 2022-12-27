#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i=2,flag=0;//用来标记相邻的数重复个数
    for(;i<=n;)
    {
        if(n%i==0)
        {
           n/=i;
           flag++;
        }
        else
        {
           if(flag==1)printf("%d ",i);//若只有一个就符合题意输入
           i++;//若无法整除就需要往后加
           flag=0;//标记清空
        }
   }
   if(flag==1)printf("%d ",i);//如果最后一个数就重复一次就输出
   return 0;
   }
      

