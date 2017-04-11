def spiralTrace(a,n):    
    for i in range(0,n):
            print a[0][i],
    
    for i in range(1,n):
            print a[i][n-1],    
    
    for i in range(n-2,-1,-1):
            print a[n-1][i],
    
    for i in range(n-2,0,-1):
            print a[i][0],

    if (n-2<=0):
        return 0
    else:
        arr = [[0 for x in range(0,n-2)] for x in range(0,n-2)]
        for i in range(1,n-1):
            for j in range(1,n-1):
                arr[i-1][j-1] = a[i][j]
        return spiralTrace(arr,len(arr))

print "Enter NxN value for array"
N = input()
a = [[0 for x in range(0,N)] for x in range(0,N)]
for i in range(0,N):
    for j in range(0,N):
        a[i][j]=input()
spiralTrace(a,len(a))
    
    


        