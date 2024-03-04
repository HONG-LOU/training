import json
import pandas as pd
import requests 
from tabulate import tabulate

nwnu = {''}
nwnu.pop()
ok = 0
path = 'D:\\codeforcesID.xlsx'
data = pd.DataFrame(pd.read_excel(path))

for i in data['ID'].values:
  nwnu.add(i)

d = []

tip = ""

for name in nwnu:
  response = requests.get("https://codeforces.com/api/user.info?handles=" + name)
  res = response.json()
  if any('result' in i for i in res):
    ok = 1
  else:
    print(name + " ==> No Info.")
    continue
  info = res['result']
  handle = info[0]['handle']
  
  na = ""
  for i in data.values:
    if i[2] == handle:
      na = i[1]
      break
  
  if any('rating' in i for i in info[0]):
    ok = 1
  else:
    tip += "%-6s" % na + " 还没有比赛信息..." + '\n'
    # print("%-6s" % na + " 还没有比赛信息...")
    continue
  # print(info)
  rating = info[0]['rating']
  
  rank = info[0]['rank']
  maxrating = info[0]['maxRating']
      
  d.append([handle, na, rank, maxrating, rating])
  
print(tip)
  
d.sort(key=lambda x: -x[3])
d[-8][1] = '马瑞'
print(tabulate(d, headers=["Handle", "Name", "Rank", "MaxRating", "Rating"], tablefmt="fancy_grid"))


#[{'contribution': 0, 'lastOnlineTimeSeconds': 1707840327, 'rating': 767, 'friendOfCount': 3, 'titlePhoto': 'https://userpic.codeforces.org/no-title.jpg', 'rank': 'newbie', 'handle': 'bmxxf', 'maxRating': 767, 'avatar': 'https://userpic.codeforces.org/no-avatar.jpg', 'registrationTimeSeconds': 1705146996, 'maxRank': 'newbie'}]