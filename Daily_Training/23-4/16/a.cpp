/**
 *    author:  HONG-LOU
 *    created: 2023-04-16 11:10:57
**/
#include <bits/stdc++.h>

using namespace std;

int findFakeCoin(int coins[], int left, int right) {
  if (left == right) {
    return left;
  }
  int middle = (left + right) / 2;
  int leftSum = 0, rightSum = 0;
  for (int i = left; i <= middle; i++) {
    leftSum += coins[i];
  }
  for (int i = middle + 1; i <= right; i++) {
    rightSum += coins[i];
  }
  if (leftSum == rightSum) {
    return findFakeCoin(coins, middle + 1, right);
  } else if (leftSum < rightSum) {
    return findFakeCoin(coins, left, middle);
  } else {
    return findFakeCoin(coins, middle + 1, right);
  }
}

auto main() -> int {
  int coins[8] = {1, 1, 1, 1, 1, 1, 0, 1};

  int fakeCoinIndex = findFakeCoin(coins, 0, 7);
  
  cout << "The fake coin is at index " << fakeCoinIndex << endl;
  return 0;
}