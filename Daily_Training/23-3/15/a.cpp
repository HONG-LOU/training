#include <bits/stdc++.h>

auto main() -> int
{
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::map<int, std::array<int, 3>> x;
  for (int i = 0; i < n; i++)
  {
    int id;
    std::cin >> id;
    char c;
    std::cin >> c >> x[id][1] >> x[id][2];
    if (c == 'M')
    {
      x[id][0] = 1;
    }
    else
    {
      x[id][0] = 0;
    }
    if (x[id][1] == -1)
    {
      x[id][1] = 0;
    }
    if (x[id][2] == -1)
    {
      x[id][2] = 0;
    }
  }
  //     std::cout << x["00011"][0] << ' ' << x["00012"][0] << "\n";
  int k;
  std::cin >> k;
  for (int i = 0; i < k; i++)
  {
    int a, b;
    std::cin >> a >> b;
    if (x[a][0] == x[b][0])
    {
      std::cout << "Never Mind"
                << "\n";
    }
    else
    {
      int a, b;
      std::cin >> a >> b;
      bool ok = true;
      if (a == b)
      {
        ok = false;
      }
      if ((x[a][1] == x[b][1] && x[a][1] != 0 && x[b][1] != 0) || (x[a][2] == x[b][2] && x[a][2] != 0 && x[b][2] != 0))
      {
        ok = false;
      }
      a = x[a][1], b = x[b][1];
      if ((x[a][1] == x[b][1] && x[a][1] != 0 && x[b][1] != 0) || (x[a][2] == x[b][2] && x[a][2] != 0 && x[b][2] != 0))
      {
        ok = false;
      }
      a = x[a][1], b = x[b][1];
      if ((x[a][1] == x[b][1] && x[a][1] != 0 && x[b][1] != 0) || (x[a][2] == x[b][2] && x[a][2] != 0 && x[b][2] != 0))
      {
        ok = false;
      }
      a = x[a][1], b = x[b][1];
      if ((x[a][1] == x[b][1] && x[a][1] != 0 && x[b][1] != 0) || (x[a][2] == x[b][2] && x[a][2] != 0 && x[b][2] != 0))
      {
        ok = false;
      }
      if (ok)
      {
        std::cout << "Yes"
                  << "\n";
      }
      else
      {
        std::cout << "No"
                  << "\n";
      }
    }
  }
}
