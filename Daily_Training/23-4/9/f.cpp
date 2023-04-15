#include <stdio.h>
#include <stdlib.h>

#define int  long long

#define MAX_N 100
#define MAX_HEAP_SIZE 1000
void minHeapify(int heap[], int i, int heapSize); // 小根堆调整函数
int kthSum(int a[], int n, int k); // 求第k小的值
signed main() {
    int a[MAX_N], n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result = kthSum(a, n, k);
    printf("%d\n", result);
    return 0;
}
void minHeapify(int heap[], int i, int heapSize) {
    int l = i * 2 + 1; // 左孩子
    int r = i * 2 + 2; // 右孩子
    int smallest = i; // 最小值的下标
    if (l < heapSize && heap[l] < heap[smallest]) {
        smallest = l;
    }
    if (r < heapSize && heap[r] < heap[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, smallest, heapSize);
    }
}
int kthSum(int a[], int n, int k) {
    int heap[MAX_HEAP_SIZE]; // 存储相加的结果
    int heapSize = 0; // 堆的大小
    for (int i = 0; i < n; i++) {
        heap[heapSize++] = a[i]; // 将数组元素存入堆中
        if (heapSize >= MAX_HEAP_SIZE) { // 如果堆满了，就进行一次堆排序
            for (int k = heapSize / 2 - 1; k >= 0; k--) {
                minHeapify(heap, k, heapSize);
            }
            heapSize = MAX_HEAP_SIZE / 2;
        }
    }
    // 进行堆排序
    for (int k = heapSize / 2 - 1; k >= 0; k--) {
        minHeapify(heap, k, heapSize);
    }
    // 依次取出最小值
    for (int i = 1; i < k; i++) {
        if (heapSize == 0) { // 如果堆已经空了，说明第k小的值不存在
            exit(0);
        }
        int min = heap[0];
        heap[0] = heap[--heapSize];
        minHeapify(heap, 0, heapSize);
        // 将新的结果加入堆中
        for (int j = 0; j < n; j++) {
            heap[heapSize++] = min + a[j];
            if (heapSize >= MAX_HEAP_SIZE) { // 如果堆满了，就进行一次堆排序
                for (int k = heapSize / 2 - 1; k >= 0; k--) {
                    minHeapify(heap, k, heapSize);
                }
                heapSize = MAX_HEAP_SIZE / 2;
            }
        }
        // 进行堆排序
        for (int k = heapSize / 2 - 1; k >= 0; k--) {
            minHeapify(heap, k, heapSize);
        }
    }
    return heap[0];
}