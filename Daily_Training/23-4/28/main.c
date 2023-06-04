#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 1000

// Huffman node
struct MinHeapNode
{
  char data;
  unsigned freq;
  struct MinHeapNode *left, *right;
};

// minheap
struct MinHeap
{
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

// new node
struct MinHeapNode *newNode(char data, unsigned freq)
{
  struct MinHeapNode *node = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
  node->left = node->right = NULL;
  node->data = data;
  node->freq = freq;
  return node;
}

// create empty huffmantree
struct MinHeap *createMinHeap(unsigned capacity)
{
  struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
  return minHeap;
}

// swap two node
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
  struct MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}

// Functions that maintain the minimum heap property
void minHeapify(struct MinHeap *minHeap, int idx)
{
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
  {
    smallest = left;
  }
  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
  {
    smallest = right;
  }
  if (smallest != idx)
  {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// Determine if the heap has only one node
int isSizeOne(struct MinHeap *minHeap)
{
  return (minHeap->size == 1);
}

// Extracting the smallest node from the heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
  struct MinHeapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  minHeap->size--;
  minHeapify(minHeap, 0);
  return temp;
}

// insert node
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
  minHeap->size++;
  int i = minHeap->size - 1;
  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
  {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

// check is it a leaf node
int isLeaf(struct MinHeapNode *root)
{
  return !(root->left) && !(root->right);
}

// create huffman tree
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createMinHeap(size);
  for (int i = 0; i < size; ++i)
  {
    insertMinHeap(minHeap, newNode(data[i], freq[i]));
  }
  while (!isSizeOne(minHeap))
  {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

#define MAX_SIZE 100

struct map
{
  char key;
  char value[MAX_SIZE];
};

int size = 0;

struct map mp[1010];

int arr[MAX_TREE_HT] = {0}, top = 0;

// print huffman code
void printCodes(struct MinHeapNode *root, int arr[], int top)
{
  // FILE* cls = fopen("huffcode.txt", "w");
  // fprintf(cls, "");
  // fclose(cls);
  FILE *output = fopen("huffcode.txt", "a");
  if (root->left)
  {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }
  if (root->right)
  {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root))
  {
    fprintf(output, "%c ", root->data);
    char cnt[100] = {0};
    for (int i = 0; i < top; ++i)
    {
      cnt[i] = (char)(arr[i] + '0');
      fprintf(output, "%d", arr[i]);
    }
    fprintf(output, "\n");
    mp[size].key = root->data;
    strcpy(mp[size].value, cnt);
    printf("%c %s\n", root->data, cnt);
    size++;
  }
  fclose(output);
}

struct MinHeapNode *root;

// huffman code
void HuffmanCodes(char data[], int freq[], int size)
{
  memset(arr, 0, sizeof arr);
  top = 0;
  root = buildHuffmanTree(data, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  printf("\nHuffman tree building completed\n\n");
  FILE *cls = fopen("huffcode.txt", "w");
  fclose(cls);
}

char barr[10101];
int bfreq[10101] = {0};

char ac[10101];
int afreq[10101] = {0};
int asize = 0;

// Initialization
void init()
{
  size = 0;
  FILE *input = fopen("sourcefile.txt", "r");
  char ch;
  memset(barr, 0, sizeof barr);
  memset(bfreq, 0, sizeof bfreq);
  int i = 0;
  while (fscanf(input, "%c", &ch) != EOF)
  {
    barr[i++] = ch;
  }
  printf("%s\n\n", barr);
  fclose(input);
}

// count freq each char
void count()
{
  memset(ac, 0, sizeof ac);
  memset(afreq, 0, sizeof afreq);
  int used[10101] = {0};
  int cnt = 0;
  for (int i = 0; i < strlen(barr); i++)
  {
    if (used[(int)barr[i]] == 0)
    {
      used[(int)barr[i]] = 1;
      ac[cnt] = barr[i];
      afreq[cnt] = 1;
      cnt++;
      continue;
    }
    for (int j = 0; j < cnt; j++)
    {
      if (ac[j] == barr[i])
      {
        afreq[j]++;
        break;
      }
    }
  }
  asize = cnt;
}

// map get mp[char c] with loop
char *find(char c)
{
  for (int i = 0; i < size; i++)
  {
    if (mp[i].key == c)
    {
      // printf("%s\n", mp[i].value);
      return mp[i].value;
    }
  }
}

// compress sourcefile.txt
void compress()
{
  FILE *input = fopen("sourcefile.txt", "r");
  FILE *output = fopen("codefile.txt", "w");

  char ch;
  while (fscanf(input, "%c", &ch) != EOF)
  {
    fflush(output);
    char cnt[1010] = {0};
    strcpy(cnt, find(ch));
    printf("%d %s\n", strlen(cnt), cnt);
    fprintf(output, "%s", cnt);
  }

  printf("\nFile compression completed\n\n");

  fclose(input);
  fclose(output);
}

// decoding codefile.txt
void decode()
{
  FILE *input = fopen("codefile.txt", "r");
  FILE *output = fopen("textfile.txt", "w");

  struct MinHeapNode *node = root;
  char ch;
  while (fscanf(input, "%c", &ch) != EOF)
  {
    if (ch == '0')
    {
      node = node->left;
    }
    else
    {
      node = node->right;
    }
    if (node->left == NULL && node->right == NULL)
    {
      fprintf(output, "%c", node->data);
      printf("%c", node->data);
      node = root;
    }
  }

  printf("\n\n");

  fclose(input);
  fclose(output);
}

// print codefile
void print()
{
  FILE *input = fopen("codefile.txt", "r");

  char ch;
  int cnt = 0;
  while (fscanf(input, "%c", &ch) != EOF)
  {
    printf("%c", ch);
    cnt++;
    if (cnt % 5 == 0)
    {
      printf("\n");
    }
  }

  printf("\n\n");

  fclose(input);
}

// Recessed table print huffmantree
void printTree(struct MinHeapNode *node, int level)
{
  if (node == NULL)
  {
    return;
  }
  for (int i = 0; i < level; i++)
  {
    printf("  ");
  }
  if (node->data == '\0')
  {
    printf("%d\n", node->freq);
  }
  else
  {
    if (node->data == '$')
    {
      printf("%d\n", node->freq);
    }
    else
    {
      printf("%c (%d)\n", node->data, node->freq);
    }
  }
  printTree(node->left, level + 1);
  printTree(node->right, level + 1);
}

// get choice
char menu()
{
  printf("========================\n");
  printf("|   Huffman ED System  |\n");
  printf("|======================|\n");
  printf("|   I.Initialization   |\n");
  printf("|      E.Encoding      |\n");
  printf("|      C.Compress      |\n");
  printf("|      D.Decoding      |\n");
  printf("|        P.Print       |\n");
  printf("|     T.Treeprinting   |\n");
  printf("|        Q.Quit        |\n");
  printf("========================\n\n");
  char ch;
  fflush(stdin);
  scanf("%c", &ch);
  printf("\n");
  return ch;
}

// main test

int main()
{
  while (1)
  {
    char ch = menu();
    if (ch == 'I')
    {
      init();
      count();
      HuffmanCodes(ac, afreq, asize);
    }
    else if (ch == 'E')
    {
      printCodes(root, arr, top);
      printf("\n");
    }
    else if (ch == 'C')
    {
      printf("%d\n", size);
      for (int i = 0; i < size; i++)
      {
        printf("%c-", mp[i].key);
      }
      compress();
    }
    else if (ch == 'D')
    {
      decode();
    }
    else if (ch == 'P')
    {
      print();
    }
    else if (ch == 'T')
    {
      printTree(root, 0);
    }
    else if (ch == 'Q')
    {
      printf("Bye-Bye!!\n\n");
      return 0;
    }
    else
    {
      printf("ERROR!\n\n");
    }
  }
  return 0;
}