#include <iostream>
using namespace std;
int quickSelect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }
    int i = left, j = right, pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (k <= j) {
        return quickSelect(arr, left, j, k);
    } else if (k >= i) {
        return quickSelect(arr, i, right, k);
    } else {
        return arr[k];
    }
}
int main() {
  int arr[] = {7, 10, 4, 3, 20, 15};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  int kthSmallest = quickSelect(arr, 0, n - 1, k - 1);
  cout << "Kth Smallest is " << kthSmallest << endl;
  return 0;
}