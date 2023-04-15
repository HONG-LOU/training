/**
 *    author:  HONG-LOU
 *    created: 2023-03-30 18:19:49
**/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;
int main() {
    int n, m, k;
    printf("Please enter the number of passengers : ");
    scanf("%d", &n);
    printf("Please enter the number of intervals between departures of passengers : ");
    scanf("%d", &m);
    printf("Please enter the number of remaining passengers : ");
    scanf("%d", &k);
    // 构建循环链表
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node* p = head;
    for (int i = 2; i <= n; i++) {
        p->next = (Node*)malloc(sizeof(Node));
        p->next->data = i;
        p = p->next;
    }
    p->next = head;  // 将链表首尾相连
    // 开始游戏
    printf("The serial number of the departing passengers are : ");
    while (n > k) {
        for (int i = 1; i < m; i++) {
            p = p->next;
        }
        Node* q = p->next;
        p->next = q->next;  // 删除节点
        printf("%d ", q->data);
        free(q);
        n--;
    }
    printf("\nThe serial numbers of the remaining passengers are : ");
    p = head;
    for (int i = 0; i < n; i++) {
        printf("%d ", p->data);
        p = p->next;
    }
    // 释放链表内存
    p = head->next;
    while (p != head) {
        Node* q = p;
        p = p->next;
        free(q);
    }
    free(head);
    return 0;
}