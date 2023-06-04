#include <stdio.h>
#include <stdlib.h>
// Huffman树结构体定义
typedef struct huffman_node
{
  int weight;
  struct huffman_node *left;
  struct huffman_node *right;
  struct huffman_node *parent;
} HuffmanNode;
// 堆节点结构体定义
typedef struct heap_node
{
  int index;
  HuffmanNode *node;
} HeapNode;
// 创建Huffman树
HuffmanNode *create_huffman_tree(int *weights, int size)
{
  // 创建节点数组并初始化
  HuffmanNode **nodes = (HuffmanNode **)malloc(size * sizeof(HuffmanNode *));
  for (int i = 0; i < size; i++)
  {
    nodes[i] = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    nodes[i]->weight = weights[i];
    nodes[i]->left = NULL;
    nodes[i]->right = NULL;
    nodes[i]->parent = NULL;
  }
  // 构建堆
  HeapNode *heap = build_heap(nodes, size);
  // 合并节点
  for (int i = 0; i < size - 1; i++)
  {
    // 从堆中取出两个权值最小的节点
    HuffmanNode *left = heap_delete(heap, &size);
    HuffmanNode *right = heap_delete(heap, &size);
    // 创建新节点并合并左右子树
    HuffmanNode *parent = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    parent->weight = left->weight + right->weight;
    parent->left = left;
    parent->right = right;
    left->parent = parent;
    right->parent = parent;
    // 将新节点插入堆中
    heap_insert(heap, parent, &size);
  }
  // 释放堆和节点数组
  free(heap);
  for (int i = 0; i < size; i++)
  {
    free(nodes[i]);
  }
  free(nodes);
  // 返回根节点
  return heap->node;
}
// 构建堆
HeapNode *build_heap(HuffmanNode **nodes, int size)
{
  // 创建堆节点数组
  HeapNode *heap = (HeapNode *)malloc(size * sizeof(HeapNode));
  // 初始化堆节点数组
  for (int i = 0; i < size; i++)
  {
    heap[i].index = i;
    heap[i].node = nodes[i];
  }
  // 从最后一个非叶子节点开始向下调整堆
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    int p = i;
    // 不断向下比较并交换节点，直到当前节点比左右子节点都小
    while (2 * p + 1 < size)
    {
      int left = 2 * p + 1;
      int right = left + 1;
      int min = left;
      if (right < size && heap[right].node->weight < heap[left].node->weight)
      {
        min = right;
      }
      if (heap[p].node->weight <= heap[min].node->weight)
      {
        break;
      }
      HeapNode tmp = heap[p];
      heap[p] = heap[min];
      heap[min] = tmp;
      heap[p].index = p;
      heap[min].index = min;
      p = min;
    }
  }
  return heap;
}
// 堆的插入和删除
void heap_insert(HeapNode *heap, HuffmanNode *node, int *size)
{
  // 将新节点插入堆末尾
  heap[*size].index = *size;
  heap[*size].node = node;
  int i = *size;
  (*size)++;
  // 不断向上比较并交换节点，直到当前节点比父节点小或已经到达根节点
  while (i > 0)
  {
    int parent = (i - 1) / 2;
    if (heap[parent].node->weight <= heap[i].node->weight)
    {
      break;
    }
    HeapNode tmp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = tmp;
    heap[parent].index = parent;
    heap[i].index = i;
    i = parent;
  }
}
HuffmanNode *heap_delete(HeapNode *heap, int *size)
{
  if (*size == 0)
  {
    return NULL;
  }
  // 将堆顶节点与最后一个节点交换，删除堆顶节点
  HuffmanNode *result = heap[0].node;
  heap[0] = heap[*size - 1];
  heap[0].index = 0;
  (*size)--;
  int i = 0;
  // 不断向下比较并交换节点，直到当前节点比左右子节点都小或已经到达叶子节点
  while (2 * i + 1 < *size)
  {
    int left = 2 * i + 1;
    int right = left + 1;
    int min = left;
    if (right < *size && heap[right].node->weight < heap[left].node->weight)
    {
      min = right;
    }
    if (heap[i].node->weight <= heap[min].node->weight)
    {
      break;
    }
    HeapNode tmp = heap[i];
    heap[i] = heap[min];
    heap[min] = tmp;
    heap[i].index = i;
    heap[min].index = min;
    i = min;
  }
  return result;
}
