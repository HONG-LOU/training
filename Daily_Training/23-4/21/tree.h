#ifndef TREE_H
#define TREE_H
// 二叉树节点结构体
typedef struct TreeNode
{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;
// 创建二叉树节点
TreeNode *createNode(int value);
// 插入节点
void insertNode(TreeNode **rootPtr, int value);
// 中序遍历
void inorderTraversal(TreeNode *root);
// 查找节点
TreeNode *searchNode(TreeNode *root, int value);
#endif