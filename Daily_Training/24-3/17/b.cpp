/**
 *    author:  HONG-LOU
 *    created: 2024-03-17 11:58:01
**/
#include <bits/stdc++.h>

const int maxn = 35;

struct node
{
  int data;
  node *l, *r;
};

int N, pre[maxn], in[maxn], post[maxn];

node* create(int postL, int postR, int inL, int inR) {
  if (postL > postR) {
    return NULL;
  }

  node* root = new node;
  root -> data = post[postR];
  int k;
  for (k = inL; k <= inR; k++) {
    if (in[k] == post[postR]) {
      break;
    }
  }
  int numLeft = k - inL;
  root->l = create(postL, postL + numLeft - 1, inL, k - 1);
  root->r = create(postL + numLeft, postR - 1, k + 1, inR);
  return root;
}

void bfs(node* root) {
  std::queue<node*> q;
  q.push(root);
  int index = 1;
  while (!q.empty()) {
    node* cur = q.front();
    q.pop();
    if (index++ != 1) {
      std::cout << ' ' << cur->data;
    }
    else {
      std::cout << cur->data;
    }
    if (cur->l != NULL) {
      q.push(cur->l);
    }
    if (cur->r != NULL) {
      q.push(cur->r);
    }
  }
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> post[i];
  }
  for (int i = 0; i < N; i++) {
    std::cin >> in[i];
  }
  node* root = create(0, N - 1, 0, N - 1);
  bfs(root);
  return 0;
}