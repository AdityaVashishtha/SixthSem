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
    
    # for i in range(0,sum+1):
    #     print i,result[i]
    return result[sum][n] ,result




def findResult(a,result,sum,n):        
    if sum <= 0:
        return
    else:        
        for i in range(1,n+1):
            if(result[sum][i] == True):
                print a[i-1]
                sum = sum - a[i-1]
                findResult(a,result,sum,n)
                break        



print "Enter numbers seprated by spaces ::"
a = [int(x) for x in raw_input().strip().split()]
print "Enter sum to find"
sum = input()
isSubset, result = subSetSum(a,sum,len(a))
if isSubset:
    print "A subset is possible"
    findResult(a,result,sum,len(a))
else:
    print "No subset is possible"
