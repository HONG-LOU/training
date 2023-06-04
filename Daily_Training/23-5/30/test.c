#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1001
#define MAXVALUE 100000

int n;
//图的关系矩阵
int matrix[MAX][MAX]={{0}};

int djstl(int s);

int main(){
    int m,x,y,k,Cc;
        scanf("%d %d",&n,&m);
            for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                                if(i!=j){
                                                matrix[i][j]=MAXVALUE;
                                                            }
                                                                    }
                                                                        }
                                                                            for(int i=0; i<m; i++){
                                                                                    scanf("%d %d",&y,&x);
                                                                                            matrix[y-1][x-1]=1;
                                                                                                    matrix[x-1][y-1]=1;
                                                                                                        }
                                                                                                            scanf("%d",&k);
                                                                                                                for(int i=0; i<k; i++){
                                                                                                                        scanf("%d",&Cc);
                                                                                                                                int sum=djstl(Cc-1);
                                                                                                                                        printf("Cc(%d)=%.2f\n",Cc,(double)(n-1)/sum);
                                                                                                                                            }
                                                                                                                                                return 0;
                                                                                                                                                }
                                                                                                                                                
                                                                                                                                                int djstl(int s){
                                                                                                                                                    int isV[MAX]={0},lowcost[MAX]={0};
                                                                                                                                                        for(int i=0; i<n; i++){
                                                                                                                                                                lowcost[i]=matrix[s][i];
                                                                                                                                                                    }
                                                                                                                                                                        isV[s]=1;
                                                                                                                                                                            int min,midIndex,sum=0;
                                                                                                                                                                                for(int i=0; i<n-1; i++){
                                                                                                                                                                                        min=MAXVALUE;
                                                                                                                                                                                                midIndex=0;
                                                                                                                                                                                                        for(int j=0; j<n; j++){
                                                                                                                                                                                                                    if(!isV[j] && lowcost[j]){
                                                                                                                                                                                                                                    if(min>lowcost[j]){
                                                                                                                                                                                                                                                        min=lowcost[j];
                                                                                                                                                                                                                                                                            midIndex=j;
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                        isV[midIndex]=1;
                                                                                                                                                                                                                                                                                                                                sum+=min;
                                                                                                                                                                                                                                                                                                                                        for(int j=0; j<n; j++){
                                                                                                                                                                                                                                                                                                                                                    if(!isV[j] && lowcost[j] && matrix[midIndex][j]){
                                                                                                                                                                                                                                                                                                                                                                    if(lowcost[j]>min+matrix[midIndex][j]){
                                                                                                                                                                                                                                                                                                                                                                                       lowcost[j]=min+matrix[midIndex][j];
                                                                                                                                                                                                                                                                                                                                                                                                       }
                                                                                                                                                                                                                                                                                                                                                                                                                   }
                                                                                                                                                                                                                                                                                                                                                                                                                           }
                                                                                                                                                                                                                                                                                                                                                                                                                               }
                                                                                                                                                                                                                                                                                                                                                                                                                                   return sum;
                                                                                                                                                                                                                                                                                                                                                                                                                                   }
                                                                                                                                                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                                                                                                                                   