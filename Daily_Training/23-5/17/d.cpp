/**
 *    author:  HONG-LOU
 *    created: 2023-05-17 19:05:57
**/
#include <bits/stdc++.h>

int x;

void change () {
	x = 10;
}	

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n = 5;
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 1);
 	auto change = [&] () {
 		for (int i = 0; i < n; i++) {
 			std::cout << a[i] << " \n"[i == n - 1];
 		}
 	}; 
 	change();                                                                     
  return 0;
}