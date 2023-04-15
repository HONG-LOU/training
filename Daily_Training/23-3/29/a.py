from textblob import TextBlob
import trans

#D:\statement\chinese_sentiment-master\data\hotel_comment\raw_data\fix_neg

'''
[-1 : 0) : neg
(0 : 1] : pos
0 : u
'''

text = "十一期间携程订的鸿展楼，网上说是四星，到地方一看怎么也不像，问服务员这是四星酒店吗？她说，是的啊，指了指大门上用红胶纸剪的四颗红五星。这就是四星，我昏。大堂人员解释，迎宾馆是四星，鸿展楼是附楼，没有四星，原来如此。房间很大，设备很旧，床单也很旧。不过价钱不贵，一天是178。早餐不太好，牛奶没有牛奶味，餐具也不是太干净。不过也不能小看这家酒店，每间房里有一本画册，上面满是朱容基、李鹏、经叔平等国家政要在这里的提字和合影留念"
s = ''
for x in text:
  if x == '。':
    x = '.'
  elif x == '，':
    x = ','
  elif x == '：':
    x = ':'
  elif x == '；':
    x = ','
  elif x == '？':
    x = '?'
  if x == ' ':
    continue
  s += x
print(s)

s = trans.translator(s)
print(s)
blob = TextBlob(s)
polarity = blob.sentiment.polarity

print(polarity)
