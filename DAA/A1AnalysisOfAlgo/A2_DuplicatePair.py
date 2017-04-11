def compare(a,i,j):
    return a[i]>a[j]

def checkDuplicate(a):
    flag =0;
    for i in range(0,len(a)):
        if(flag!=1):
            for j in range(i+1,len(a)):
                if (not(compare(a,i,j) or compare(a,j,i))) and flag==0:
                    print "Duplicate Pair of(",a[i],")Found: at ",i," and ",j
                    flag = 1
                    break            
        else:
            break

print "Enter the number of Input to enter"
n = input()
a = [0 for x in range(0,n)]
print "Enter list of number"
for i in range(0,n):
    a[i]=input()
from time import time 
t1 = time()
checkDuplicate(a)
print "Excecution time:", round(time()-t1, 3), "s"