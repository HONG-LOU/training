import json
import requests 
from tabulate import tabulate

nwnu = {'xingliu', 'huanshao2341', 'yumingjs', 'Souture', 'Abinnn'}

d = []

for name in nwnu:
  response = requests.get("https://codeforces.com/api/user.info?handles=" + name)
  res = response.json()
  info = res['result']
  rating = info[0]['rating']
  handle = info[0]['handle']
  rank = info[0]['rank']
  maxrating = info[0]['maxRating']
  d.append([handle, rank, maxrating, rating])
  
d.sort(key=lambda x: -x[3])
print(tabulate(d, headers=["Handle", "Rank", "MaxRating", "Rating"], tablefmt="fancy_grid"))
