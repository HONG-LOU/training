#include <iostream>

using namespace std;

int cmp(char a, char b);
char G(char r[], int n);

int main()
{
  char a[100];
  int i, n;
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> a[i];
  cout << G(a, n) << endl;
  return 0;
}

char G(char r[], int n)
{
  int i = n;
  while (i > 1)
  {
    i = i / 2;
    for (int j = 0; j < i; j++)
    {
      if (cmp(r[j + i], r[j]))
        r[j] = r[j + i];
    }
  }
  return r[0];
}

int cmp(char a, char b)
{
  return a > b ? 1 : 0;
}
