def fibo1(a):
    if a<= 1 :
        return 1
    else:
        return fibo1(a-1) + fibo1(a-2)

def fibo2(a):
    nextVal = 1
    old = 0
    temp = 0
    for i in range(0,a):
        if (i<2):            
			old=1
			nextVal=1
        else :
            temp = old
            old = nextVal
            nextVal = temp + nextVal		
    return nextVal

print "Enter a Number"
a = input()
ans = fibo1(a-1)
print ans
ans = fibo2(a)
print ans