file = open("input").read().strip().split(',')

tab = []
for line in file:
    tmp = line.split('-')

    tab.append(tmp[0])
    tab.append(tmp[1])

for line in tab:
    print(int(line))
