#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  
  stack<string> s1, s2;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string a;
    cin >> a;
    if (a == "Enter")
    {
      string b;
      cin >> b;
      std::cout << b << "\n";
      s1.push(b);
      while (s2.size() != 0)
      {
        s2.pop();
      }
    }
    else if (a == "Back")
    {
      if (s1.size() <= 1)
      {
        std::cout << "Error" << "\n";
      }
      else
      {
        s2.push(s1.top());
        s1.pop();
        std::cout << s1.top() << "\n";
      }
    }
    else
    {
      if (s2.size() < 1)
      {
        std::cout << "Error" << "\n";
      }
      else
      {
        s1.push(s2.top());
        s2.pop();
        std::cout << s1.top() << "\n";
      }
    }
  }
  return 0;
}