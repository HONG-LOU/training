from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
import os
import requests as rq
from bs4 import BeautifulSoup as bs
import re


down_load_dir = os.path.abspath(".")
options = webdriver.ChromeOptions()
options.add_experimental_option("excludeSwitches", ['enable-automation'])
prefs = {
    "download.default_directory": down_load_dir,
    "download.prompt_for_download": False,
    "download.directory_upgrade": True,
    "plugins.always_open_pdf_externally": True
}
options.add_experimental_option('prefs', prefs)
options.add_argument("--disable-blink-features=AutomationControlled")
browser = webdriver.Chrome(options=options)

browser.execute_cdp_cmd("Page.addScriptToEvaluateOnNewDocument", {
    "source": """
    Object.defineProperty(navigator, 'webdriver', {
      get: () => undefined
    })
  """
})

# browser.get(url)

# a1 = browser.find_element(By.CLASS_NAME, "verlist")

# # print(a1.text)

# # for i in a1:
# #   print(i)

# # time.sleep(5)

# data = browser.page_source

# td = str(data)

# sr = ""

# # print(td)

# pre = "http://chinafilmnews.cn/UploadFiles/"

# for i in range(len(td) - 4):
#   if td[i] == 'f' and td[i + 1] == 'i' and td[i + 2] == 'l' and td[i + 3] == 'e':
#     j = i
#     while (td[j] != '"' or td[j + 1] != ' ' or td[j + 2] != 't'):
#       sr += td[j]
#       j = j + 1
    
#     linklist.append(sr)
#     sr = ""
    

# print(data)
# 获取文档的下载链接
# soup = BeautifulSoup(data)
# body = soup.find('li', attrs={'class': 'y'})


# body = soup.find('li', attrs={})

# for i in body:
#   print(str(i))
#   link = i.find_all("a")[0].get("href")
#   nlink = 'http://chinafilmnews.cn'
#   for j in range(5, len(link)):
#     nlink += link[j]
  
#   linklist.append(nlink)
  
  
# linklist.append(nlink)
# print('\n\n[' + nlink + ']\n\n')

# 有了开始对 options 的设置，这一步可以直接下载 PDF 文档
# browser.get(link)
# time.sleep(5)
# browser.close()

# print(linklist)

# browser.get("http://chinafilmnews.cn/UploadFiles/file/20240410/202404100904053720.pdf")

# -*- coding: utf-8 -*-
import io
import requests

def download_pdf(save_path,pdf_name,pdf_url):
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

# url = "http://chinafilmnews.cn/UploadFiles/file/"

# browser.get(url)


# all_url = browser.find_element(By.TAG_NAME, 'a')

# print(str(all_url))

def gethtml(rooturl, encoding="utf-8"):
  # 默认解码方式utf-8
  response = rq.get(rooturl)
  response.encoding = encoding
  html = response.text
  return html  # 返回链接的html内容

def getherf(html):
    # 使用BeautifulSoup函数解析传入的html
    soup = bs(html, features="lxml")
    allnode_of_a = soup.find_all("a")
    result = [_.get("href") for _ in allnode_of_a]
    # print(result)
    return result

def filterurl(result):
    # result参数：get到的所有a标签内herf的内容
    # 对列表中每个元素进行筛选
    urlptn = r"http://(.+)"  # 匹配模式: 所有http://开头的链接
    urls = [re.match(urlptn, str(_)) for _ in result]  # 正则筛选
    # print(urls)
    while None in urls:
        urls.remove(None)  # 移除表中空元素
    urls = [_.group() for _ in urls]  # group方法获得re.match()返回值中的字符
    # print(urls)
    return urls

html = gethtml("http://chinafilmnews.cn/UploadFiles/file/")
result = getherf(html)
urls = filterurl(result)
print(urls)


# save_path = 'D:/PDF/'
# pdf_name='showpdf'
# pdf_url="http://chinafilmnews.cn/UploadFiles/file/20240410/202404100904053720.pdf"
# download_pdf(save_path, pdf_name, pdf_url)
  
