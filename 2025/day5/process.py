ranges = open("raw_ranges").read().strip().split()

tab = []
for rang in ranges:
    tmp = rang.split('-')

    tab.append(tmp[0])
    tab.append(tmp[1])

for rang in tab:
    print(int(rang))



