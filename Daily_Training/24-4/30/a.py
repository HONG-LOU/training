import re
with open('res.in', 'r', encoding='utf-8') as file:
    lines = file.readlines()
    a = [line.strip() for line in lines if re.search(r'\b西北师范大学\b', line)]
with open('ans.out', 'w', encoding='utf-8') as file:
    for item in a:
        file.write(item + "\n")