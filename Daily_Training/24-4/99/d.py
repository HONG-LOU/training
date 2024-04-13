import numpy as np

# https://oeis.org/A052980

a = np.zeros(100001)

a[1] = 1
a[2] = 2
a[3] = 5

for i in range(4, 100001):
  a[i] = a[i - 1] * 2 + a[i - 3]
  a[i] %= 10000
  
x = int(input())
ans = int(a[x])
print(ans)