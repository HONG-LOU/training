#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[101010];
int index = 0;

typedef struct TreeNode
{
  char data;              // 节点数据
  struct TreeNode *left;  // 左子树指针
  struct TreeNode *right; // 右子树指针
} TreeNode;
// 创建二叉树
TreeNode *createBinaryTree()
{
  char data = arr[index];
  if (data == '\0' || data == ')')
  {
    return NULL;
  }
  if (data != ',') {
    index++;
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = createBinaryTree(arr, index);
    
  }
  if (data == ',') {
    index++;
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->right = createBinaryTree(arr, index);
  }
  if (data == '(') {
    index++;
    
  }
  
  return node;
}
// 先序遍历二叉树
void preorderTraversal(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  printf("%c ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
int main()
{
  strcpy(arr, "A(B(D,E(H(,K(L,M(N)))),C(F,G(,I)))");
  int index = 0;
  TreeNode *root = createBinaryTree();
  printf("Order View : ");
  preorderTraversal(root);
  printf("\n");
  return 0;
}