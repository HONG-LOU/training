with open('test.out', 'r', encoding='utf-8') as file:
    lines = file.readlines()
new_lines = []
for line in lines:
    if line[-2] == '是':
        line = line[:-3] + '\n'
        print('???')
        
    line = line[19:]
    new_lines.append(line)
with open('fin.out', 'w', encoding='utf-8') as file:
    file.writelines(new_lines)