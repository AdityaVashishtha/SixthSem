LOCAL_MAX = 1000000000000

def distance(x,y):
    x1=x[0]
    y1=x[1]
    x2=y[0]
    y2=y[1]
    return pow(((x1-x2)**2 + (y1-y2)**2),0.5)

def minDistance(a,l,r):
    min = LOCAL_MAX   
    x = [0,0]    
    y = [0,0]
    for i in range(l,r):
        for j in range(i+1,r):
            dist = distance(a[i],a[j])            
            if dist < float(min) :
                min = dist
                x=a[i]
                y=a[j]
    
    return min,x,y

def minimumToMid(a,l,r,dmin,x,y):
    min = dmin    
    a = sorted(a,key= lambda a:a[1])
    for i in range(l,r):
        for j in range(i+1,r):
            if (a[j][1]-a[i][1])>min :
                break
            else:
                dist = distance(a[i],a[j])
                if dist < min :
                    min = dist
                    x = a[i]
                    y = a[j]
    return min,x,y


def closest(a,l,r):
    #print minDistance(a,l,r)
    #termination condition
    x = [0,0]    
    y = [0,0]
    if (r-l) <=3:
        return minDistance(a,l,r)

    mid = l+(r-l)/2
    midX = a[mid]
    #calculating minimum of left and right
    dMinL,x1,y1 = closest(a,l,mid)
    dMinR,x2,y2 = closest(a,mid+1,r)
    dmin = min(dMinL,dMinR)
    if(dmin==dMinL):
        x,y = x1,y1
    else:
        x,y = x2,y2
    #calculating middle minimum
    middle =[]
    for i in range(l,r):
        if abs(a[i][0]-midX[0]) < dmin:
            middle.append(a[i])
    #comparing left minimum and right minimum to minimum of Mid
    midMin,x,y = minimumToMid(middle,0,len(middle),dmin,x,y)  
    if (dmin < midMin):
        return dmin,x,y
    else :
        return midMin,x,y
    


def closestStart(a):
    a = sorted(a)
    d,x,y= closest(a,0,len(a))
    print "Closes Point are (",x[0],",",x[1],") and (",y[0],",",y[1],")"
    print "With Distance :: ",d


MAX = 1000000
from random import randint
print "Enter number of points to enter::"
n=input()
a=[[0,0] for i in range(0,n)]
print "Input in the form:: x y"
for i in range(0,n):
    x=[randint(0,MAX-1),randint(0,MAX-1)]
    a[i] = x

#a = [[2, 3], [12, 30], [40, 50], [5, 1], [12, 10], [12, 4]]
print a
from time import time
t0 = time()
if(len(a)>1):
    closestStart(a)
t1 = time()
print "Total Execution time :: ",round(t1-t0,5)