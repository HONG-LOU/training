#include <stdio.h>
#include <stdlib.h>
 
int yinzisum(int x){
	int i=1,sum=0;
	if(x==1)
		return 1;
	while(i<x){
		if(x%i==0)
			sum+=i;
		i++;
	}
	return sum;
}
int main(){
	int x,y;
	int i,j;
	int flag=0;
	scanf("%d%d",&x,&y);
	int min,max;
	if(x>y){
		max=x;
		min=y;
	}else{
		max=y;
		min=x;
	}
	int *array=(int *)malloc(sizeof(int)*(max-min+1));
	for(i=0;i<max-min+1;i++)
		array[i]=yinzisum(min+i);//将区间内数的因子之和存储在数组中
	for(i=0;i<max-min+1;i++){
		for(j=i+1;j<max-min+1;j++){
			if(array[i]==j+min&&array[j]==i+min){
				printf("%d %d\n",i+min,j+min);
				flag=1;
			}
		}
	}
	if(flag==0)
		printf("NONE\n");
	return 0;
}