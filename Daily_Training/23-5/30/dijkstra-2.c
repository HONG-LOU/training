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

typedef struct {
    int to;
    int next;
} Edge;

int n, m, i, j;
int head[maxsize], cnt;
Edge edge[maxsize * 2];

void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

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
        for (int e = head[t.id]; e != -1; e = edge[e].next) {
            int v = edge[e].to;
            if (!vis[v] && dist[v] > dist[t.id] + 1) {
                dist[v] = dist[t.id] + 1;
                node x = {v, dist[v]};
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
    int k, cc;
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof(head));
    cnt = 0;
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        addEdge(u, v);
        addEdge(v, u);
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