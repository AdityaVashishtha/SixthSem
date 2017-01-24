#using nth root formula newtons method
def powerUsingNthRoot(a,b):
   """TODO ADD BODY TO FUNCTION"""

#this method uses expansion of a^x for calculating power of numbers
def powerUsingExpansion(a,b):
    from math import log,factorial
    MAX = 15
    result = 0
    fact = 1
    for i in range(0,MAX):
        A = b*log(a)
        A = POW(A,i)
        if(i!=0):
            fact *= i
        A = A/fact
        result = result + A
    return result

#this method helps powerUsingExpansion() method for internal operations
def POW(a,b):
    result =1
    for i in range(0,b):
        result *= a
    return result
    
print "Enter 2 numbers"
a = input()
b = input()

from time import time

t1 = time()
x = pow(a,b)
print "Excecution time:", round(time()-t1, 3), "s"
print "Method 1 Using default function : %.4f" % x

t1 = time()
print "Method 2 Using Expantion Series : %.4f" % powerUsingExpansion(a,b)
print "Excecution time:", round(time()-t1, 3), "s"