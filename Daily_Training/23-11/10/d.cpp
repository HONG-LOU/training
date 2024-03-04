#include <iostream>
#define MaxSize 256
using namespace std;
typedef char ElemType;

typedef struct tree
{
  tree *Left;
  ElemType data;
  tree *Right;
} BTree;

// 种树
void CreateTree(BTree *&root, char *str)
{
  BTree *St[MaxSize], *p;
  int top = -1, k, j = 0;
  char flag = str[j];
  root = NULL;
  while (flag != '\0')
  {
    switch (flag)
    {
    case '(':
      top++;
      St[top] = p;
      k = 1;
      break; // 节点入栈，为左节点K=1
    case ',':
      k = 2;
      break; // 右节点K=2
    case ')':
      top--;
      break; // 退栈一次
    default:
      p = new BTree; // 创建一个新节点，储存数据
      p->data = flag;
      p->Left = p->Right = NULL;
      if (root == NULL) // 判断是否为 根
        root = p;
      else
      {
        switch (k) // 判断左右节点
        {
        case 1:
          St[top]->Left = p;
          break;
        case 2:
          St[top]->Right = p;
          break;
        }
      }
    }
    j++;
    flag = str[j]; // 继续遍历
  }
}

// 砍树
void DestroyTree(tree *&t)
{
  if (t != NULL)
  {
    DestroyTree(t->Left);
    DestroyTree(t->Right);
    delete t;
  }
}

// 先序遍历
void PreOrder(tree *&t)
{
  if (t == NULL)
    return;
  else
  {
    cout << t->data << " ";
    PreOrder(t->Left);
    PreOrder(t->Right);
  }
}

// 先序凹入表示
void APreOrder(tree *t, int deep, int k)
{
  if (t == NULL)
    return;

  for (int i = 0; i < deep; i++) // 输出前导空格
    cout << "   ";

  cout << t->data; // 输出数据

  for (int j = 0; j < (30 - 3 * deep); j++) // 输出“=”
    cout << "=";

  if (!deep) // 判断是否为根节点
    cout << "Root";
  else
  {
    if (k == 1) // 判断左右节点
      cout << "L";
    else
      cout << "R";
  }
  cout << endl;
  APreOrder(t->Left, deep + 1, 1); // deep深度增加，k为判断左右节点
  APreOrder(t->Right, deep + 1, 0);
}

// 中序遍历
void InOrder(tree *&t)
{
  if (t == NULL)
    return;
  else
  {
    InOrder(t->Left);
    cout << t->data << " ";
    InOrder(t->Right);
  }
}

// 中序凹入表示法
void AInOrder(tree *&t, int deep, int k)
{
  if (t == NULL)
    return;

  AInOrder(t->Left, deep + 1, 1);

  for (int i = 0; i < deep; i++) // 输出前导空格
    cout << "   ";

  cout << t->data; // 输出数据

  for (int j = 0; j < (30 - 3 * deep); j++) // 输出“=”
    cout << "=";

  if (!deep)
    cout << "Root";
  else
  {
    if (k == 1) // 判断左右节点
      cout << "L";
    else
      cout << "R";
  }
  cout << endl;

  AInOrder(t->Right, deep + 1, 0);
}

// 后序遍历
void PostOrder(tree *&t)
{
  if (t == NULL)
    return;
  else
  {
    PostOrder(t->Left);
    PostOrder(t->Right);
    cout << t->data << " ";
  }
}

// 后序凹入表示法
void APostOrder(tree *&t, int deep, int k)
{
  if (t == NULL)
    return;

  APostOrder(t->Left, deep + 1, 1);
  APostOrder(t->Right, deep + 1, 0);

  for (int i = 0; i < deep; i++) // 输出前导空格
    cout << "   ";

  cout << t->data; // 输出数据

  for (int j = 0; j < (30 - 3 * deep); j++) // 输出“=”
    cout << "=";

  if (!deep) // 判断是否为根节点
    cout << "Root";
  else
  {
    if (k == 1) // 判断左右节点
      cout << "L";
    else
      cout << "R";
  }
  cout << endl;
}

// 层次遍历
void LevelOrder(tree *&t)
{
  BTree *Data[MaxSize]; // 利用指针组来模拟队列
  int front, rear, flag;
  front = 0, rear = -1;
  flag = 0;
  if (t != NULL) // 判断树是否为空
  {
    rear++;              // 尾指针加1
    Data[rear] = t;      // 根节点进队
    while (flag <= rear) // 用flag依次判断进队节点是否有孩子
    {
      if (Data[flag]->Left != NULL) // 存在左孩子就进队
      {
        rear++;
        Data[rear] = Data[flag]->Left;
      }
      if (Data[flag]->Right != NULL) // 存在右孩子就进队
      {
        rear++;
        Data[rear] = Data[flag]->Right;
      }
      flag++; // 寻找下个节点是否有孩子
    }
  }
  if (rear != -1) // 队列是否为空
  {
    while (front <= rear) // 出队
    {
      cout << Data[front]->data << " ";
      front++;
    }
  }
}

// 括号表示法输出二叉树
void DispTree(tree *t)
{
  if (t != NULL)
  {
    cout << t->data;
    if (t->Left != NULL || t->Right != NULL) // 存在孩子
    {
      cout << "("; // 有孩子就打印“（”
      DispTree(t->Left);
      if (t->Right != NULL)
        cout << ","; // 有右孩子就打印“）”
      DispTree(t->Right);
      cout << ")";
    }
  }
}

// 左右树转换
void TurnTree(tree *&t)
{
  if (t == NULL)
    return;
  else
  {
    TurnTree(t->Left);
    TurnTree(t->Right);
    BTree *p; // 创建中转节点
    p = t->Left;
    t->Left = t->Right;
    t->Right = p;
  }
}

int main()
{
  char a[100] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
  tree *bt;
  CreateTree(bt, a);

  cout << "1PreOrder: ";
  PreOrder(bt);
  cout << endl;

  // cout << "2.中序遍历：";
  // InOrder(bt);
  // cout << endl;

  // cout << "3.后序遍历：";
  // PostOrder(bt);
  // cout << endl;

  // cout << "4.层次遍历：";
  // LevelOrder(bt);
  // cout << endl;

  // int d = 0, k; // d记录树递归的深度，k标记左右孩子

  // cout << "5.先序遍历（凹入表示法）：" << endl;
  // APreOrder(bt, d, k);

  // cout << "6.中序遍历（凹入表示法）：" << endl;
  // AInOrder(bt, d, k);

  // cout << "7.后序遍历（凹入表示法）：" << endl;
  // APostOrder(bt, d, k);

  // cout << "8.二叉树节点转换：";
  // TurnTree(bt);
  // DispTree(bt);
  // cout << endl;

  DestroyTree(bt);
  return 0;
}