def multiply(a,b):
    if(a<10 or b<10):
        return (a*b)
    x=str(a)
    y=str(b)
    lenA=len(x)
    lenB=len(y)
    xUHalf = int(x[0:(lenA/2)])
    yUHalf = int(y[0:(lenB/2)])
    xLHalf = int(x[(lenA/2):])
    yLHalf = int(y[(lenB/2):])

    p0=multiply(xUHalf,yUHalf)
    p1=multiply(xLHalf,yLHalf)
    p2=multiply(xLHalf+xUHalf,yLHalf+yUHalf) - p0 -p1
    return (p0*(pow(10,lenA))) + (p2*pow(10,lenA/2)) + p1



print "Enter numbers"
a=input()
b=input()
if a>b:
    print "Result of multiplication is :: ",multiply(a,b)
else:
    print "Result of multiplication is :: ",multiply(b,a)