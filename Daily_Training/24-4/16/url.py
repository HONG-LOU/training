import requests
from bs4 import BeautifulSoup
import re

import io


def download_pdf(save_path,pdf_name,pdf_url):
    print(pdf_name)
    send_headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36",
        "Connection": "keep-alive",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8",
        "Accept-Language": "zh-CN,zh;q=0.8"}
    response = requests.get(pdf_url, headers=send_headers)
    bytes_io = io.BytesIO(response.content)
    with open(save_path + "%s.PDF" % pdf_name, mode='wb') as f:
        f.write(bytes_io.getvalue())
        print('%s.PDF,下载成功！' % (pdf_name))


ans = ""

url = 'https://chinafilmnews.cn/search.php?page=6&Key=%E9%9F%A9%E5%9B%BD%E7%94%B5%E5%BD%B1&x=0&y=0'
# res = requests.get(url)
# https://chinafilmnews.cn/search.php?page=2&Key=%E9%9F%A9%E5%9B%BD%E7%94%B5%E5%BD%B1&x=0&y=0

ul = "https://chinafilmnews.cn/Html/"

ans = ""

cnt = 1

for ii in range(1, 13):
  url = 'https://chinafilmnews.cn/search.php?page=' + str(ii) + '&Key=%E9%9F%A9%E5%9B%BD%E7%94%B5%E5%BD%B1&x=0&y=0'

  res = requests.get(url)
  print(url)
  soup = BeautifulSoup(res.text, 'lxml')
  for a in soup.find_all('dt'):
      # print(a['href'])
      # s = url + a['href']
      # print(str(a))
      # print(a.key)
      sul = ul
      for i in a:
        title = i.text
        print(title)
        ans = title
        si = str(i)
        index = 39
        while si[index] != 'l':
          index = index - 1
        
        for j in range(17, index + 1):
          sul += si[j]
        
        print(sul)
        rres = requests.get(sul)
        ssoup = BeautifulSoup(rres.content, 'lxml')
        for b in ssoup.find_all('p'):
          sen = b.text
          if (sen[:4] != '友情链接'):
            ans += sen
            ans += '\n'
        # print(ans)
        fs = 'result' + str(cnt) + '.txt'
        cnt = cnt + 1
        f = open(fs, 'w', encoding='utf-8')
        f.write(ans)
        f.close()
  