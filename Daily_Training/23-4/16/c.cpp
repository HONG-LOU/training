#include <iostream>
using namespace std;
int ternarySearch(int arr[], int left, int right, int k) {
    if (left > right) {
        return -1;  // 未找到
    }
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    if (arr[mid1] == k) {
        return mid1;  // 找到
    } else if (arr[mid2] == k) {
        return mid2;  // 找到
    } else if (k < arr[mid1]) {
        return ternarySearch(arr, left, mid1 - 1, k);  // 在左侧序列中查找
    } else if (k > arr[mid2]) {
        return ternarySearch(arr, mid2 + 1, right, k);  // 在右侧序列中查找
    } else {
        return ternarySearch(arr, mid1 + 1, mid2 - 1, k);  // 在中间序列中查找
    }
}
int main() {
  int arr[] = {1, 3, 4, 6, 7, 9, 11, 15, 19};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 7;
  int index = ternarySearch(arr, 0, n - 1, k);
  if (index == -1) {
    cout << "Not Found" << endl;
  } else {
    cout << "Index ==> " << index << endl;
  }
  return 0;
}