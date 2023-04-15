/*最近对问题*/ 
#include<stdio.h>

struct Postion{
	double x;
	double y;
}P[5050];

void BruteForceClosePoints(Postion P[], int n, int *index1, int *index2){
	double min = 10000;
	double  d;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			d = (P[i].x - P[j].x)*(P[i].x - P[j].x) + (P[i].y - P[j].y)*(P[i].y - P[j].y);
			if(d < min){
				min = d;
				*index1 = i;
				*index2 = j;
			}
		}
	}
	printf("%lf", min);
}

int main(){
  freopen("test.txt", "r", stdin);
	int n, index1,index2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf%lf", &P[i].x, &P[i].y);
	} 
	BruteForceClosePoints(P, n, &index1, &index2);
  fclose(stdin);
  return 0;
} 

