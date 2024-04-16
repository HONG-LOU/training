


import requests
from bs4 import BeautifulSoup
url = 'https://chinafilmnews.cn/UploadFiles/file/'
res = requests.get(url)
soup = BeautifulSoup(res.text, 'lxml')
for a in soup.find_all('a'):
    # print(a['href'])
    s = url + a['href']
    # print(s)
    sres = requests.get(s)
    asoup = BeautifulSoup(sres.text, 'lxml')
    for b in asoup.find_all('a'):
      print(b['href'])
# print('*'*100)

