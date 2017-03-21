def LongestSubSequence(X,Y,Z):    
    m = len(X)
    n = len(Y)
    o = len(Z)
    b = [[[0 for i in range(0,o)] for i in range(0,n)] for i in range(0,m)]
    c = [[[0 for i in range(0,o+1)] for i in range(0,n+1)] for i in range(0,m+1)]
    for i in range(0,m+1):
        c[i][0][0] = 0
    for i in range(0,n+1):
        c[0][i][0] = 0
    for i in range(0,o+1):
        c[0][0][i] = 0
    

    for i in range(0,m):
        for j in range(0,n):
            for k in range(0,o):
                if(X[i] == Y[j] and Y[j]==Z[k] ):
                    c[i][j][k] = c[i-1][j-1][k-1]+1
                    b[i][j][k] = 4
                elif c[i-1][j][k] >= c[i][j-1][k] and  c[i-1][j][k] >= c[i][j][k-1]:
                    c[i][j][k] = c[i-1][j][k]
                    b[i][j][k] = 1
                elif c[i][j-1][k] >= c[i-1][j][k] and  c[i][j-1][k] >= c[i][j][k-1]:
                    c[i][j][k] = c[i][j-1][k]
                    b[i][j][k] = 2
                else:
                    c[i][j][k] = c[i][j][k-1]
                    b[i][j][k] = 3
    
    return c,b

import sys

def printLCS(b,X,i,j,k):
    if i < 0 or j < 0 or k < 0:
        return 0
    if b[i][j][k]==4:
        printLCS(b,X,i-1,j-1,k-1)
        sys.stdout.write(X[i])
    elif b[i][j][k]==3:
        printLCS(b,X,i,j,k-1)
    elif b[i][j][k]==2:
        printLCS(b,X,i,j-1,k)
    else:
        printLCS(b,X,i-1,j,k)


print "Enter 3 Strings ::"
X = raw_input()
Y = raw_input()
Z = raw_input()
c,b = LongestSubSequence(X,Y,Z)
m = len(X)
n = len(Y)
o = len(Z)
print c[m-1][n-1][o-1]
printLCS(b,X,m-1,n-1,o-1)
print ""
