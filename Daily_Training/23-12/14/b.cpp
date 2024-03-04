/**
 *    author:  HONG-LOU
 *    created: 2023-12-14 10:42:35
**/
#include <bits/stdc++.h>
#include <windows.h>

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  const int n = 100;
  const int timediff = 50;

  while (true) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + 2; j++) {
        std::cout << '-';
      }
      std::cout << "\n|";
      for (int j = 0; j < n; j++) {
        if (j <= i + 1 && j >= i - 1) {
          std::cout << 'B';
        }
        else {
          std::cout << '-';
        }
      }
      std::cout << "|\n";
      for (int j = 0; j < n + 2; j++) {
        std::cout << '-';
      }
      std::cout << "\n";
      Sleep(timediff);
      system("cls");
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < n + 2; j++) {
        std::cout << '-';
      }
      std::cout << "\n|";
      for (int j = 0; j < n; j++) {
        if (j <= i + 1 && j >= i - 1) {
          std::cout << 'B';
        }
        else {
          std::cout << '-';
        }
      }
      std::cout << "|\n";
      for (int j = 0; j < n + 2; j++) {
        std::cout << '-';
      }
      std::cout << "\n";
      Sleep(timediff);
      system("cls");
    }
  }
  return 0;
}