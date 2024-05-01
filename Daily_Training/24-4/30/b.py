import re
with open('ans.out', 'r', encoding='utf-8') as file:
    lines = file.readlines()
new_lines = []
for line in lines:
    for i in range(1, len(line) - 1):
      if (line[i - 1] == ' ' and line[i + 1] == ' '):
        line = line[:i - 1] + line[i:]
    new_lines.append(line)
lines = new_lines
new_lines = []
for line in lines:
    for i in range(2, len(line) - 5):
      if (line[i] == ' ' and (line[i + 1:i + 5] == '程序设计' or line[i + 1:i + 5] == '软件开发' or line[i + 1:i + 5] == '设计与开')):
        line = line[:i] + line[i + 1:]
    new_lines.append(line)
with open('test.out', 'w', encoding='utf-8') as file:
    file.writelines(new_lines)
    