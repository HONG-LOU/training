#include <stdio.h>

#define MAXN 105
 
int n;
int done[MAXN] = {0};
 
struct node {
    int deadLine;
    int weight; 
} thing[MAXN];
 

 
void Init() {
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &thing[i].deadLine);
    for (i = 1; i <= n; i++)
        scanf("%d", &thing[i].weight);
    for(i = 0;i <= n; i++)
        done[i] = 1;
}

int Done(struct node t) {
    int i;
    for(i = t.deadLine; i >= 1; i--)
        if(done[i]) {
            done[i] = 0;
            return 1;
        }

    return 0;
}
 
long long Calc() {
    int i, j;
    for (i = 1; i <= n - 1; i++) {
      for (j = i + 1; j <= n; j++) {
        if (thing[i].weight == thing[j].weight && thing[j].deadLine < thing[i].deadLine) {
          int temp = thing[i].deadLine;
          thing[i].deadLine = thing[j].deadLine;
          thing[j].deadLine = temp;
        }
        else if (thing[j].weight > thing[i].weight) {
          int temp = thing[i].weight;
          thing[i].weight = thing[j].weight;
          thing[j].weight = temp;
          temp = thing[i].deadLine;
          thing[i].deadLine = thing[j].deadLine;
          thing[j].deadLine = temp;
        }
      }
    }
 
    long long ans= 0;
    for (i = 1; i <= n; i++) {
      ans += thing[i].weight;
    }
    for(i = 1; i <= n; i++) {
        if(Done(thing[i]) == 0)
            ans += thing[i].weight;
    }
    return ans;
}
 
int main() {
    Init();
    printf("%lld\n", Calc());
}

