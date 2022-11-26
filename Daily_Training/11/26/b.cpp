#include<bits/stdc++.h>

const int N =(int) 2e5 + 17;

std::vector<int> a(N, 0), b(N, 0), c(N, 0);

auto main() -> int {
  int n, m;
  std::cin >> n >> m;
  for(int i = n; i; i--) std::cin >> a[i];
  for(int i = m; i; i--) std::cin >> b[i];
  n = std::max(n, m);
  for(int i = 1; i <= n; i++){
    c[i] += a[i] + b[i];
    c[i + 1] = c[i] / (i + 1);
    c[i] %= (i + 1);
  }
  if(c[n + 1]) printf("%d ", c[n + 1]);
  for(int i = n; i; i--) printf("%d ",c[i]);
  return 0;
}