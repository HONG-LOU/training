tt = int(input())

for t in range(tt):
  n = int(input())
  print(n*(n+1)*(4*n-1)//6 * 2022 % 1000000007)