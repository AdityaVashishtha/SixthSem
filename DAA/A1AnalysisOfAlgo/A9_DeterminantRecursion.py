def determinant(a,l,m):
    n = len(a)
    if(n<=1):
        return a[0][0]
    else:
        sum = 0
        temp = [[[0 for i in range(0,n-1)] for j in range(0,n-1)] for k in range(0,n)]
        A = []
        for o in range(0,n):
            del A[:]
            for i in range(0,n):
                for j in range(0,n):
                    if (j!=o and i!=l):                        
                        A.append(a[i][j])

            k =0
            for i in range(0,len(temp[0])):
                for j in range(0,len(temp[0])):
                    temp[o][i][j] = A[k]
                    k += 1
            del A[:]
        for o in range(0,n):
            if (((l+o)%2)==0):
                sum = sum + a[l][o]*determinant(temp[o], l, o)
            else:
                sum = sum - a[l][o]*determinant(temp[o], l, o)
        
        return sum

print "Enter dimension of array NxN: "
N = input()
a = [[0 for i in range(0,N)] for j in range(0,N)]
for i in range(0,N):
    for j in range(0,N):
        a[i][j]=input()
from time import time
t1 = time()   
print "Determinant is : ",determinant(a,0,0)
print "Excecution time:", round(time()-t1, 3), "s"