#include <iostream>
using namespace std;

int num_arr[2] = { 0 };
int max_num = 0;

int main() {
  int n, temp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (i < 1) {
      max_num = temp;
      num_arr[0] = temp;
      continue;
    }
    num_arr[i % 2] = max(temp, temp + num_arr[(i + 1) % 2]);
    max_num = num_arr[i % 2] > max_num ? num_arr[i % 2] : max_num;
  }

  cout << max_num;
  return 0;
}

