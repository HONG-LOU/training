#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *l, *r;
}Node, *Tree;

int sea(Tree T, int key, Tree f, Tree *p) {
  if (!T) {
    *p = f;
    return 0;
  }
  else if (key == T -> val) {
    *p = T;
    return 1;
  }
  else if (key < T -> val) {
    return sea(T -> l, key, T, p);
  }
  else {
    return sea(T -> r, key, T, p);
  }
}

int insert(Tree *T, int key) {
  Tree p, s;
  if (!sea(*T, key, NULL, &p)) {
    s = (Tree) malloc(sizeof(Node));
    s -> val = key;
    s -> l = s -> r = NULL;
    if (!p) {
      *T = s;
    }
    else if (key < p -> val) {
      p -> l = s;
    }
    else {
      p -> r = s;
    }
    return 1;
  }
  else {
    return 0;
  }
}

void delete(Tree *p) {
  Tree q, s;
  if (!(*p) -> l && !(*p) -> r) {
    *p = NULL;
  }
  else if (!(*p) -> l) {
    q = *p;
    *p = (*p) -> r;
    free(q);
  }
  else if (!(*p) -> r) {
    q = *p;
    *p = (*p) -> l;
    free(q);
  }
  else {
    q = *p;
    s = (*p) -> l;
    while (s -> r) {
      q = s;
      s = s -> r;
    }
    (*p) -> val = s -> val;
    if (q != *p) {
      q -> l = s -> l;
    }
    else {
      q -> l = s -> l;
    }
    free(s);
  }
}

int deleteNode(Tree *T, int key) {
  if (!(*T)) {
    return 0;
  }
  else {
    if (key == (*T) -> val) {
      delete(T);
      return 1;
    }
    else if (key < (*T) -> val) {
      return deleteNode(&(*T) -> l, key);
    }
    else {
      return deleteNode(&(*T) -> r, key);
    }
  }
}

void printTree(Node* T) {
  if (T) {
    printTree(T -> l);
    printf("%d ", T -> val);
    printTree(T -> r);
  }
}

int max(int a, int b) {
  return a > b ? a : b;
}

int ans = 0;

int deepth(Node* T, int deep) {
  if (T) {
    ans = max(ans, deep);
    if (T -> l) {
      deepth(T -> l, deep + 1);
    }
    if (T -> r) {
      deepth(T -> r, deep + 1);
    }
  }
}

int a[101010] = {0};

int main() {
  int n;
  Tree T = NULL;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    insert(&T, a[i]);
  }
  deepth(T, 1);
  printTree(T);
  printf("\n");
  printf("%d\n", ans);
  deleteNode(&T, 4);
  printTree(T);
}