def multiply(a,n):
    carry = 0
    for i in range(0,len(a)):
        x = a[i]*n + carry
        a[i] = x%10 
        carry = x/10
    while (carry%10)!=0:
        a.append(carry%10)
        carry = carry/10
    return a

def factorial(num):
    output = []
    output.append(1)
    for i in range(2,num+1):
        output = multiply(output,i)
    return output
        

import sys
print "Enter Number for factorial"
a = raw_input().split()[0]
output = factorial(int(a))
output.reverse()
for i in output:
    sys.stdout.write(str(i))    
print ""