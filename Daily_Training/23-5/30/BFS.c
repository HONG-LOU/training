#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxsize 1000

typedef struct {
    int to;
    int next;
} Edge;

int head[maxsize], cnt;
Edge edge[maxsize * 2];

void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int n, m, i, j;

typedef struct {
    int id;
    int next;
    int prev;
} Node;

typedef struct {
    int head;
    int tail;
    int cnt;
    Node node[maxsize];
} Queue;

void initQueue(Queue *q) {
    q->head = -1;
    q->tail = -1;
    q->cnt = 0;
}

void pushBack(Queue *q, int id) {
    if (q->cnt == 0) {
        q->head = q->tail = id;
        q->node[id].prev = q->node[id].next = -1;
    } else {
        q->node[id].prev = q->tail;
        q->node[id].next = -1;
        q->node[q->tail].next = id;
        q->tail = id;
    }
    q->cnt++;
}

int popFront(Queue *q) {
    if (q->cnt == 0) {
        return -1;
    } else {
        int id = q->head;
        q->head = q->node[id].next;
        if (q->head != -1) {
            q->node[q->head].prev = -1;
        } else {
            q->tail = -1;
        }
        q->cnt--;
        return id;
    }
}

int bfs(int start) {
    int vis[maxsize] = {0};
    int dist[maxsize];
    Queue q;
    initQueue(&q);
    for (i = 0; i < n; i++) {
        dist[i] = -1;
    }
    pushBack(&q, start);
    dist[start] = 0;
    vis[start] = 1;
    while (q.cnt != 0) {
        int u = popFront(&q);
        for (int e = head[u]; e != -1; e = edge[e].next) {
            int v = edge[e].to;
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                pushBack(&q, v);
            }
        }
    }
    int sum = 0;
    int unconnected_graph = 0;
    for (i = 0; i < n; i++) {
        if (i != start) sum += dist[i];
        if (dist[i] == -1) {
                unconnected_graph = 1;
        }
    }
    return unconnected_graph ? 0 : sum;
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
        int sum = bfs(cc);
        printf("Cc(%d)=%.2f\n", cc + 1, (double) (n - 1) / sum);
    }
    return 0;
}
