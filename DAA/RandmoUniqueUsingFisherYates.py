print "Enter Max number limit"
MAX = input()
a = [x for x in range(0,MAX)]
from random import randint
print "Enter number of unique random number to generate(<MAX)"
lengthOfList = input()
if lengthOfList <=MAX:
    for i in range(0,lengthOfList):
        index = randint(0,MAX-1)
        print a[index]
        #swapping of index and decrement of MAX
        temp = a[index]
        a[index] = a[MAX-1]
        a[MAX-1] = temp
        MAX -=1
        