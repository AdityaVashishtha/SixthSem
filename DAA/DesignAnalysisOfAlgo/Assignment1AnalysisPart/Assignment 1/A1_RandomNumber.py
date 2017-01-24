def fisherYates(num):
    MAX = 1000000
    a = [x for x in range(0,MAX)]
    from random import randint
    lengthOfList = num
    if lengthOfList <=MAX:
        for i in range(0,lengthOfList):
            index = randint(0,MAX-1)
            print a[index]
            #swapping of index and decrement of MAX
            temp = a[index]
            a[index] = a[MAX-1]
            a[MAX-1] = temp
            MAX -=1

def linearCongruential(num):
    listLength = num
    X = 1
    l = 492876864
    c = 15485863
    m = 492876863
    check = set()
    for i in range(0,listLength):
        X = (l * X + c )%m
        print X  
        check.add(X)
    print "Accuracy : ", float(len(check))/float(num)

print "Enter Choice: "
print "1. Random Number using Fisher Yates Shuffling"
print "2. Random Number using Linear Congruential"
ch = input()
if(ch==1):
    fisherYates(input())
elif ch==2:
    linearCongruential(input())
else:
    print "wrong choice"