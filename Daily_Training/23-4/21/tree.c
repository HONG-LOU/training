#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
// 创建二叉树节点
TreeNode *createNode(int value)
{
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}
// 插入节点
void insertNode(TreeNode **rootPtr, int value)
{
  if (*rootPtr == NULL)
  {
    *rootPtr = createNode(value);
    return;
  }
  if (value < (*rootPtr)->value)
  {
    insertNode(&((*rootPtr)->left), value);
  }
  else
  {
    insertNode(&((*rootPtr)->right), value);
  }
}
// 中序遍历
void inorderTraversal(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  inorderTraversal(root->left);
  printf("%d ", root->value);
  inorderTraversal(root->right);
}
// 查找节点
TreeNode *searchNode(TreeNode *root, int value)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (value < root->value)
  {
    return searchNode(root->left, value);
  }
  else if (value > root->value)
  {
    return searchNode(root->right, value);
  }
  else
  {
    return root;
  }
}