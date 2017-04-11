def setInterval(s,f,b):
	n = len(s)
	A = []
	A.append(b[0])
	k = 1
	for i in range(2,n):
		if s[i] >= f[k] :
			A.append(b[i])
			k = i

	#print A
			

	

print "Enter Number of elements"
n = input()
MAX = 100000000
from random import randint
s = []
f = []
k = []
for i in range(0,n):
	x,y = [randint(0,MAX-1),randint(0,MAX-1)] #[int(x) for x in raw_input().strip().split()]
	s.append(x)
	f.append(y)
	k.append([x,y])

from time import time
t0 = time()
#print k
f.sort()
setInterval(s,f,k)
t1 = time()
print "Total Execution time :: ",(t1-t0)


	
