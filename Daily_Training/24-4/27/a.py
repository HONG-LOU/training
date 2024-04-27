import jieba
from collections import Counter

year = ['2015', '2021', '2024']
# 读取三届政府工作报告文本数据
report_texts = []
for i in range(3):
  print('\n\n' + year[i] + ':')
  report_texts = []
  with open(f'政府工作报告_{i+1}.txt', 'r', encoding='utf-8') as f:
    report_texts.append(f.read())
  
  total_words = []
  for text in report_texts:
    seg_list = jieba.cut(text)
    total_words.extend(seg_list)
  # 统计词频并选取出现最多的前100个词语
  word_counts = Counter(total_words)

  top_100_words = word_counts.most_common(100)
  # 输出前100个主题词语及其出现次数

  # extra = ['，', '。', '、', ' ', '“', '”']

  for word, count in top_100_words:
    if len(word) == 1 or word=='习近平':
      continue
    print(f'{word}: {count}', end=' ')
  # 分析热点话题及其变化
  # 可以观察每届报告中出现频率较高的词语，比较不同届之间的变化，来分析热点话题及其变化趋势