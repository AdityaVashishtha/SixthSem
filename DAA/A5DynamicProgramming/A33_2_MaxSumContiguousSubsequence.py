def maxSumSubSeq(a):
    maxSum = -99999999999
    maxend = 0
    maxINew = 0
    maxI = 0
    maxJ = 0
    for i in range(0,len(a)):
        maxend = maxend + a[i]        
        if(maxend < 0):
            maxend = 0                        
            maxINew = i+1
        if(maxSum < maxend):
            maxI = maxINew
            maxSum = maxend
            maxJ = i             
    
    for i in range(maxI,maxJ+1):
        print(a[i])
    return maxSum



print "Enter the numbers space seprated :: "
a = [int(x) for x in raw_input().strip().split()]
maxSum = maxSumSubSeq(a)
print "Max Contiguous Sum is :: ",maxSum