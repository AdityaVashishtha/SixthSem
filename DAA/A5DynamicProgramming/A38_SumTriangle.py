def maxSumTriangle(a,n):
    for i in range(n-2,-1,-1):
        for j in range(0,len(a[i])):
           a[i][j] = a[i][j] + max(a[i+1][j],a[i+1][j+1])

    print "Max Sum is ::",a[0][0]
    


print "enter number of rows :: "
n = input()
print "enter each row from 1 to n space seprated ::"
a = []
wiFlag = False
for i in range(0,n):
    x = [int(x) for x in raw_input().strip().split()]
    if(len(x) == i+1):
        a.append(x)
    else:
        print "Wrong Input!!"
        wiFlag = True
        break
if not wiFlag:
    maxSumTriangle(a,n)
