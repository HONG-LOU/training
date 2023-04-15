/**
 *    author:  HONG-LOU
 *    created: 2023-04-03 21:33:31
 **/

#include <bits/stdc++.h>

using namespace std;

struct point {
  int x;
  int y;
};

int Partition(point S[], int first, int end) {
  int i = first, j = end;
  while (i < j) {
    while (i < j && S[i].y <= S[j].y) j--;
    if (i < j) {
      point temp;
      temp = S[i];
      S[i] = S[j];
      S[j] = temp;
      i++;
    }
    while (i < j && S[i].y <= S[j].y) i++;
    if (i < j) {
      point temp;
      temp = S[i];
      S[i] = S[j];
      S[j] = temp;
      j--;
    }
  }
  return i;
}

void QuickSort(point S[], int first, int end) {
  int pivot;
  if (first < end) {
    pivot = Partition(S, first, end);
    QuickSort(S, first, pivot - 1);
    QuickSort(S, pivot + 1, end);
  }
}

double Distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Closest(point S[], int low, int high) {
  double d1, d2, d3, d;
  int mid, i, j, index;
  point P[1000];
  if (high - low == 1) return Distance(S[low], S[high]);
  if (high - low == 2) {
    d1 = Distance(S[low], S[low + 1]);
    d2 = Distance(S[low + 1], S[high]);
    d3 = Distance(S[low], S[high]);
    if ((d1 < d2) && (d1 < d3)) return d1;
    else if (d2 < d3) return d2;
    else return d3;
  }
  mid = (low + high) / 2;
  d1 = Closest(S, low, mid);
  d2 = Closest(S, mid + 1, high);
  if (d1 <= d2) d = d1;
  else d = d2;
  index = 0;
  for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--) P[index++] = S[i];
  for (i = mid + 1; (i <= high) && (S[i].x - S[mid].x < d); i++);
  QuickSort(P, 0, index - 1);
  for (i = 0; i < index; i++) {
    for (j = i + 1; j < index; j++) {
      if (P[i].y - P[i].y >= d) break;
      else {
        d3 = Distance(P[i], P[j]);
        if (d3 < d) d = d3;
      }
    }
  }
  return d;
}

auto main () -> int {
  struct point S[5050];
  freopen("test.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i].x >> S[i].y;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (S[j].x > S[j + 1].x) {
        point temp = S[j + 1];
        S[j + 1] = S[j];
        S[j] = temp;
      }
    }
  }
  cout << Closest(S, 0, n - 1);
  fclose(stdin);
}
