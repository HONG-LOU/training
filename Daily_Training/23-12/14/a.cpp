/**
 *    author:  HONG-LOU
 *    created: 2023-12-14 10:01:33
**/
#include <bits/stdc++.h>
#include <windows.h>

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;

  double timec = 0;

  std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
  std::vector<std::vector<char>> dir(n, std::vector<char>(n, ' '));

  auto check = [&] (int step) {
    return (step == n * n);
  };

  auto print = [&] {
    for (int i = 0; i < 2 * n + 1; i++) {
      std::cout << '-';
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << '|' << dir[i][j];
      }
      std::cout << "|\n";
      for (int j = 0; j < 2 * n + 1; j++) {
        std::cout << '-';
      }
      std::cout << "\n";
    }
    std::cout << "\n";
    Sleep(100);
    system("cls");
  };

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  auto checkposition = [&] (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  };

  std::function<void(int, int, int)> dfs = [&] (int x, int y, int deep) {
    print();
    if (check(deep)) {
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (checkposition(nx, ny) && !vis[nx][ny]) {
        dir[nx][ny] = '*';
        vis[nx][ny] = true;
        dfs(nx, ny, deep + 1);
        vis[nx][ny] = false;
        dir[nx][ny] = ' ';
        print();
      }
    }
  };

  auto start = std::chrono::steady_clock::now();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vis[i][j] = true;
      dir[i][j] = 'B';
      dfs(i, j, 0);
      vis[i][j] = false;
    }
  }

  auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << "Execution time: " << std::chrono::duration<double, std::milli>(diff).count() << "ms" << std::endl;
  return 0;
}