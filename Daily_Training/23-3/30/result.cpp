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

  Node* head = (Node*)malloc(sizeof(Node));
  head -> data = 1;
  Node* p = head;
  
  for (int i = 2; i <= n; i++) {
    p -> next = (Node*)malloc(sizeof(Node));
    p -> next -> data = i;
    p = p -> next;
  }

  p -> next = head;

  printf("The serial number of the departing passengers are : ");
  while (n > k) {
    for (int i = 1; i < m; i++) {
        p = p -> next;
    }
    Node* q = p -> next;
    p -> next = q -> next;
    printf("%d ", q -> data);
    free(q);
    n--;
  }

  printf("\nThe serial numbers of the remaining passengers are : ");
  for (int i = 0; i < n; i++) {
    printf("%d ", p->data);
    p = p -> next;
  }

  p = head -> next;
  while (p != head) {
    Node* q = p;
    p = p -> next;
    free(q);
  }

  free(head);
  return 0;
}