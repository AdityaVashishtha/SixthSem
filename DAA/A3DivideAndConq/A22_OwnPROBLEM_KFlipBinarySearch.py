def kBinarySearch(a,l,r,x):
    if(l<=r):
        mid = l + (r-l)/2
        #print a[mid]
        if(a[mid]==x):
            # print "=---",a[mid]
            return mid
        elif(x>a[mid]):
            if(x>a[mid] and x<=a[r]):
                return kBinarySearch(a,mid+1,r,x)
            else:
                return kBinarySearch(a,l,mid-1,x)
        elif(x<a[mid]):
            if(x<a[mid] and x>=a[l]):
                return kBinarySearch(a,l,mid-1,x)                
            else:
                return kBinarySearch(a,mid+1,r,x)
        else:
            return -1

from time import time
print "Enter number of test cases"
n = input()
a =[]
for i in range(0,n):
    a.append(i+1)
#print a
print "Enter number of flips:"
k = n/2 #input()
b=[]
for i in range(0,k):
    b.append(a[n-k+i])

for i in range(0,n-k):
    b.append(a[i])


#print b
# print "MID ::",
x = n/2+1 #input()
t0 = time()
index = kBinarySearch(b,0,len(b)-1,x)
t1 = time()
print "Total Execution time :: ",t1-t0

if(index >= 0):
    print "INDEX AT ::",index
else:
    print "NOT FOUND"
