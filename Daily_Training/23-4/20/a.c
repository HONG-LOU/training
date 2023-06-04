#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义哈夫曼树节点结构体
struct HufNode {
    char ch;
    int freq;
    struct HufNode *left, *right;
};
//定义哈夫曼编码结构体
struct HufCode {
    char ch;
    char *code;
};
//定义最小堆结构体
struct MinHeap {
    int size;
    int capacity;
    struct HufNode **array;
};
//新建一个哈夫曼树节点
struct HufNode *newNode(char ch, int freq) {
    struct HufNode *temp = (struct HufNode *)malloc(sizeof(struct HufNode));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}
//新建一个哈夫曼编码结构体
struct HufCode *newCode(char ch, char *code) {
    struct HufCode *temp = (struct HufCode *)malloc(sizeof(struct HufCode));
    temp->ch = ch;
    temp->code = (char *)malloc(strlen(code) + 1);
    strcpy(temp->code, code);
    return temp;
}
//交换两个哈夫曼树节点
void swapNode(struct HufNode **a, struct HufNode **b) {
    struct HufNode *temp = *a;
    *a = *b;
    *b = temp;
}
//最小堆化
void minHeapify(struct MinHeap *minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != index) {
        swapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}
//判断最小堆的大小是否为1
int isSizeOne(struct MinHeap *minHeap) {
    return minHeap->size == 1;
}
//提取最小堆中的最小值
struct HufNode *extractMin(struct MinHeap *minHeap) {
    struct HufNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
//插入一个哈夫曼树节点到最小堆中
void insertMinHeap(struct MinHeap *minHeap, struct HufNode *node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}
//建立哈夫曼树
struct HufNode *buildHuffmanTree(char data[], int freq[], int size) {
    struct HufNode *left, *right, *top;
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array = (struct HufNode **)malloc(minHeap->capacity * sizeof(struct HufNode *));
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
        ++minHeap->size;
    }
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
//递归获得哈夫曼编码
void getCode(struct HufNode *root, char *code, int len, struct HufCode *hufCode[]) {
    if (root->left) {
        code[len] = '0';
        getCode(root->left, code, len + 1, hufCode);
    }
    if (root->right) {
        code[len] = '1';
        getCode(root->right, code, len + 1, hufCode);
    }
    if (!root->left && !root->right) {
        hufCode[root->ch] = newCode(root->ch, code);
    }
}
//编码
char *encode(struct HufCode *hufCode[], char *input) {
    int len = strlen(input);
    char *output = (char *)malloc(len * sizeof(char));
    int k = 0;
    for (int i = 0; i < len; ++i) {
        char ch = input[i];
        struct HufCode *code = hufCode[ch];
        for (int j = 0; j < strlen(code->code); ++j) {
            output[k++] = code->code[j];
        }
    }
    output[k] = '\0';
    return output;
}
//压缩文件
void compressFile(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        printf("Error: Could not open file %s\n", inputFile);
        return;
    }
    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        printf("Error: Could not create file %s\n", outputFile);
        return;
    }
    //统计文件中每个字符出现的频率
    int freq[256] = {0};
    char ch;
    while (fscanf(in, "%c", &ch) != EOF) {
        freq[ch]++;
    }
    //建立哈夫曼树
    char data[256];
    for (int i = 0; i < 256; ++i) {
        data[i] = i;
    }
    struct HufNode *root = buildHuffmanTree(data, freq, 256);
    //生成哈夫曼编码
    char code[256];
    struct HufCode *hufCode[256] = {NULL};
    getCode(root, code, 0, hufCode);
    //将哈夫曼编码写入文件
    fprintf(out, "HUFFMAN");
    for (int i = 0; i < 256; ++i) {
        if (hufCode[i]) {
            fprintf(out, "%c%s", hufCode[i]->ch, hufCode[i]->code);
        }
    }
    fprintf(out, "EOF");
    //将压缩后的文件写入输出文件
    fseek(in, 0, SEEK_SET);
    char *input = (char *)malloc(freq[0] * sizeof(char));
    while (fscanf(in, "%s", input) != EOF) {
        char *output = encode(hufCode, input);
        fprintf(out, "%s", output);
        free(output);
    }
    //释放内存并关闭文件
    free(input);
    fclose(in);
    fclose(out);
}
//译码
void decode(struct HufNode *root, char *input, int len, FILE *out) {
    struct HufNode *temp = root;
    for (int i = 0; i < len; ++i) {
        if (input[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        if (!temp->left && !temp->right) {
            fprintf(out, "%c", temp->ch);
            temp = root;
        }
    }
}
//解压缩文件
void decompressFile(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        printf("Error: Could not open file %s\n", inputFile);
        return;
    }
    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        printf("Error: Could not create file %s\n", outputFile);
        return;
    }
    //检查文件头
    char header[8];
    fscanf(in, "%s", header);
    if (strcmp(header, "HUFFMAN") != 0) {
        printf("Error: Invalid input file format\n");
        return;
    }
    //读取哈夫曼编码
    struct HufCode *hufCode[256] = {NULL};
    char ch, *code;
    while (fscanf(in, "%c", &ch) != EOF && ch != 'E') {
        code = (char *)malloc(256 * sizeof(char));
        fscanf(in, "%s", code);
        hufCode[ch] = newCode(ch, code);
    }
    //建立哈夫曼树
    int freq[256] = {0};
    for (int i = 0; i < 256; ++i) {
        if (hufCode[i]) {
            freq[i] = strlen(hufCode[i]->code);
        }
    }
    char data[256];
    for (int i = 0; i < 256; ++i) {
        data[i] = i;
    }
    struct HufNode *root = buildHuffmanTree(data, freq, 256);
    //译码并写入输出文件
    char *input = (char *)malloc(256 * sizeof(char));
    int len = 0;
    while (fscanf(in, "%s", input) != EOF) {
        len = strlen(input);
        decode(root, input, len, out);
    }
    //释放内存并关闭文件
    free(input);
    for (int i = 0; i < 256; ++i) {
        if (hufCode[i]) {
            free(hufCode[i]->code);
            free(hufCode[i]);
        }
    }
    fclose(in);
    fclose(out);
}
//显示哈夫曼树
void printHuffmanTree(struct HufNode *root, int level) {
    if (root) {
        printHuffmanTree(root->right, level + 1);
        printf("\n");
        for (int i = 0; i < level; ++i) {
            printf("    ");
        }
        printf("(%c,%d)", root->ch, root->freq);
        printHuffmanTree(root->left, level + 1);
    }
}
int main() {
    char inputFile[256], outputFile[256];
    int choice;
    printf("1. Compress file\n2. Decompress file\n3. Print Huffman tree\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter input file name: ");
            scanf("%s", inputFile);
            printf("Enter output file name: ");
            scanf("%s", outputFile);
            compressFile(inputFile, outputFile);
            printf("File compressed successfully.\n");
            break;
        case 2:
            printf("Enter input file name: ");
            scanf("%s", inputFile);
            printf("Enter output file name: ");
            scanf("%s", outputFile);
            decompressFile(inputFile, outputFile);
            printf("File decompressed successfully.\n");
            break;
        case 3:
            //统计文件中每个字符出现的频率
            printf("Enter input file name: ");
            scanf("%s", inputFile);
            int freq[256] = {0};
            char ch;
            FILE *in = fopen(inputFile, "rb");
            if (!in) {
                printf("Error: Could not open file %s\n", inputFile);
                return 0;
            }
            while (fscanf(in, "%c", &ch) != EOF) {
                freq[ch]++;
            }
            fclose(in);
            //建立哈夫曼树
            char data[256];
            for (int i = 0; i < 256; ++i) {
                data[i] = i;
            }
            struct HufNode *root = buildHuffmanTree(data, freq, 256);
            //显示哈夫曼树
            printf("Huffman tree:\n");
            printHuffmanTree(root, 0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}