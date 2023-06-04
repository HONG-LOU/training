#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxsize 2000
const int maxvalue = (int) 1e5;

int n, i, j;

int g[maxsize][maxsize] = {{0}};

int dijkstra (int start) {
	int vis[maxsize] = {0};
	int lowcost[maxsize] = {0};
	for (i = 0; i < n; i++) {
		lowcost[i] = g[start][i];
	}
	vis[start] = 1;
	int min, minIndex, sum = 0;
	for (i = 0; i < n - 1; i++) {
		min = maxvalue;
		minIndex = 0;
		for (j = 0; j < n; j++) {
			if (!vis[j] && lowcost[j] && lowcost[j] < min) {
				min = lowcost[j];
				minIndex = j;
			}
		}
		vis[minIndex] = 1;
		sum += min;
		for (j = 0; j < n; j++) {
			if (!vis[j] && lowcost[j] && g[minIndex][j]) {
				if (lowcost[j] > min + g[minIndex][j]) {
					lowcost[j] = min + g[minIndex][j];
				}
			}
		}
	}
	return sum;
}

int main () {
	int m, k, cc;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			g[i][j] = maxvalue;
		}
	}
	for (i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &cc);
		cc--;
		int sum = dijkstra(cc);
		printf("%d\n", sum);
		printf("Cc(%d)=%.2f\n", cc + 1, (double) (n - 1) / sum);
	}
	return 0;
}