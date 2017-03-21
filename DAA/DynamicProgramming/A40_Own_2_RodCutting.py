def CutRod(p,n):
    INTMIN = -9999999999
    r = [0 for i in range(0,n+1)]
    s = [0 for i in range(0,n+1)]
    r[0] = 0
    for j in range(1,n+1):
        q = INTMIN        
        for i in range(0,j):
            if q < (p[i] + r[j-i-1]):
                q = (p[i] + r[j-i-1]);
                s[j] = i+1
        r[j] = q
    return r,s


def PrintCutRod(s,n):
    while n > 0 :
        print s[n]
        n = n - s[n]

print "Enter the max length of rod available"
n = input()
print "Enter available rod price for length 1-n"
p = [0 for i in range(0,n)]
for i in range(0,n):
    p[i] = input()

r,s = CutRod(p,n)
print "Max Profit ", r[n]
#print s
print "Rod should be of size :: "
PrintCutRod(s,n)

