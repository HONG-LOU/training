import pandas as pd
data = []
with open('nwnu.out', 'r', encoding='utf-8') as file:
    lines = file.readlines()
    for line in lines:
        items = line.strip().split()
        # 确保每行有三个元素
        if len(items) == 3:
            if (items[2] == '一等奖'):
              items.append("是")
            data.append(items)

df = pd.DataFrame(data, columns=['姓名', '赛道', '获奖情况', '是否进入国赛'])
df.to_excel('output.xlsx', index=False)