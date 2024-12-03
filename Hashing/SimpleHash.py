names = ["alice", "brad", "collin", "collin", "brad", "dylan", "kim"]

countMap = {}
for name in names:
    if name not in countMap:
        countMap[name] = 1
    else:
        countMap[name] += 1

print(countMap)
