LOCAL_MAX = 1000000000000

def distance(x,y):
    x1=x[0]
    y1=x[1]
    x2=y[0]
    y2=y[1]
    return pow(((x1-x2)**2 + (y1-y2)**2),0.5)

def minDistance(a,l,r):
    min = LOCAL_MAX
    for i in range(l,r):
        for j in range(i+1,r):
            dist = distance(a[i],a[j])            
            if dist < float(min) :
                min = dist
    return min

def minimumToMid(a,l,r,dmin):
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
    return min


def closest(a,l,r):
    #print minDistance(a,l,r)
    #termination condition
    if (r-l) <=3:
        return minDistance(a,l,r)

    mid = l+(r-l)/2
    midX = a[mid]
    #calculating minimum of left and right
    dMinL = closest(a,l,mid)
    dMinR = closest(a,mid+1,r)
    dmin = min(dMinL,dMinR)
    #calculating middle minimum
    middle =[]
    for i in range(l,r):
        if abs(a[i][0]-midX[0]) < dmin:
            middle.append(a[i])
    #comparing left minimum and right minimum to minimum of Mid
    midMin = minimumToMid(middle,0,len(middle),dmin)  
    return min(dmin,midMin)
    


def closestStart(a):
    a = sorted(a)
    print closest(a,0,len(a))


print "Enter number of points to enter::"
n=input()
a=[[0,0] for i in range(0,n)]
print "Input in the form:: x y"
for i in range(0,n):
    x=[int(x) for x in raw_input().strip().split()]
    a[i] = x

#a = [[2, 3], [12, 30], [40, 50], [5, 1], [12, 10], [12, 4]]

closestStart(a)