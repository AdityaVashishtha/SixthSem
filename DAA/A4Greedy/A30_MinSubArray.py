def findMin(a,i,j,k,n):
    if(i<j):
        sum =0
        for m in range(i,j):
            sum = sum + a[m]
        print "sum is ", sum,k
        if sum > 0:
            k +=1            
            k = findMin(a,j,n,k,n)
            return k
        else:            
            k = findMin(a,i,j-1,k,n)    
    elif (i<n):
           k = findMin(a,i+1,j,k,n)    
    return k



    
print "Enter number of elements"
n = input()
a = []
MAX = 100000000
from random import randint
print "Enter elements"
for i in range(0,n):
    x = randint(0,MAX-1)#input()
    temp = randint(0,MAX)
    if(temp%2 == 0):
        x = -x    
    a.append(x)

from time import time
t0 = time()

sum = 0
m = 0
i=0
while i<n:
    #print "i->",i
    sum = 0
    for j in range(n-1,i-1,-1):
        sum = sum + a[j]
    for j in range(n-1,i-1,-1):
        if sum > 0:
            i = j
            m+=1
            break
        else :
            sum = sum - a[j] 
    i+=1

print m
t1 = time()
print "Total Execution time :: ",(t1-t0)
# k = 0
# k = findMin(a,0,n,k,n)
# print k