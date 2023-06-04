#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxsize 2000
const int maxvalue = (int) 1e5;

typedef struct {
    int id;
    int dist;
} node;

typedef struct {
    int size;
    node data[maxsize];
} Heap;

int n, i, j;

int g[maxsize][maxsize] = {{0}};

void init(Heap *heap) {
    heap->size = 0;
}

void insert(Heap *heap, node x) {
    int i = ++heap->size;
    while (i > 1 && heap->data[i / 2].dist > x.dist) {
        heap->data[i] = heap->data[i / 2];
        i /= 2;
    }
    heap->data[i] = x;
}

node pop(Heap *heap) {
    node res = heap->data[1];
    node x = heap->data[heap->size--];
    int i = 1, j = 2;
    while (j <= heap->size) {
        if (j < heap->size && heap->data[j].dist > heap->data[j + 1].dist) j++;
        if (x.dist <= heap->data[j].dist) break;
        heap->data[i] = heap->data[j];
        i = j;
        j *= 2;
    }
    heap->data[i] = x;
    return res;
}

int dijkstra(int start) {
    Heap heap;
    init(&heap);
    int vis[maxsize] = {0};
    int dist[maxsize];
    for (i = 0; i < n; i++) {
        dist[i] = maxvalue;
    }
    dist[start] = 0;
    node s = {start, 0};
    insert(&heap, s);
    while (heap.size > 0) {
        node t = pop(&heap);
        if (vis[t.id]) continue;
        vis[t.id] = 1;
        for (i = 0; i < n; i++) {
            if (!vis[i] && g[t.id][i] && dist[i] > dist[t.id] + g[t.id][i]) {
                dist[i] = dist[t.id] + g[t.id][i];
                node x = {i, dist[i]};
                insert(&heap, x);
            }
        }
    }
    int sum = 0;
    for (i = 0; i < n; i++) {
        if (i != start) sum += dist[i];
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