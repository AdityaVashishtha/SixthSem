print "Enter Number of elements"
c = input()
a = [0 for i in range(0,c)]
for i in range(0,c):
	a[i] = input()
#a = [int(x) for x in raw_input().split()]
# TIME CALCULATION FUNCTION
from time import time
t1 = time()

a.sort()

max_k=0;
k=0;
temp =0;
f=[]

for i in range(0,c):
	temp = a[i]-k
	if((temp==1)and(a[i]!=1)):
		max_k +=1
	else:
		f.append(max_k+1)
		max_k =0
	k = a[i]

print "This array is ",max(f)," Straight."
print "Excecution time:", round(time()-t1, 3), "s"
