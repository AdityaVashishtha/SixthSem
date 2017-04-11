def subSetSum(a,sum,n):
    result = [[False for i in range(0,n+1)] for i in range(0,sum+1)]
    for i in range(0,n+1):
        result[0][i] = True
    
    for i in range(1,sum+1):
        result[i][0] = False
        
    for i in range(1,sum+1):
        for j in range(1,n+1):            
            result[i][j] = result[i][j-1]            
            if i >= a[j-1]:                
                result[i][j] = result[i][j] or result[i-a[j-1]][j-1];                                           
    
    for i in range(0,sum+1):
        if result[i][n]:
            print i
    return result[sum][n] ,result



print "Enter numbers seprated by spaces ::"
a = [int(x) for x in raw_input().strip().split()]
print "Distinct Possible sum from above numbers are ::"
sum = sum(a)
isSubset, result = subSetSum(a,sum,len(a))
