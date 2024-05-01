with open('fin.out', 'r', encoding='utf-8') as file:
    lines = file.readlines()
sorted_lines = sorted(lines, key=lambda x: x[-4:])
with open('nwnu.out', 'w', encoding='utf-8') as file:
    file.writelines(sorted_lines)