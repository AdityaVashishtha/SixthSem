listLength = input()
X = 1
checkSet = set()
for i in range(0,listLength):
    X = (105534 * X + 9733)%105533
    print X
    checkSet.add(X)

print "(The PRoof)UNIQUE PERCENT : ",len(checkSet)