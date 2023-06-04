/**
 *    author:  HONG-LOU
 *    created: 2023-05-20 20:50:12
**/
#include <bits/stdc++.h>

class DSU {
  public:
      std::vector<int> p;
          int n;
            
            DSU(int size) : n(size) {
                p.resize(size);
                    std::iota(p.begin(), p.end(), 0);
                      }
                      
                        inline int get(int x) {
                            return (x == p[x] ? x : (p[x] = get(p[x])));
                              }
                              
                                inline bool merge(int x, int y) {
                                    x = get(x);
                                        y = get(y);
                                        
                                            if (x != y) {
                                                  p[x] = y;
                                                        return true;
                                                            }
                                                                return false;
                                                                  }
                                                                  

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  
  return 0;
}