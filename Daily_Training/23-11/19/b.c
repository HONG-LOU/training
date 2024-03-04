#include <stdio.h>

int search(int list[], int n, int x)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (list[i] == x)
    {
      return i + 1;
    }
  }
  return -1;
}

int main()
{
  int n = 0;
  scanf("%d", &n);
  int list[n];
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &list[i]);
  }
  int x;
  scanf("%d", &x);
  int ans = search(list, n, x);
  printf("%d", ans);
  return 0;
}