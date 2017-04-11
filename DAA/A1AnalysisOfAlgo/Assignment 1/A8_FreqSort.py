print "Enter Number of elements"
c = input()
MAX = 1000000
a = []
b = []
index=0
freq=0
for i in range(0,c):
	t = input()
	a = [x[0] for x in b]
	if(t in a):
		print "yes"
		index = a.index(t)
		b[index][1] += 1
	else:
		b.append([t,1])

b = sorted(b,key=lambda x:x[1],reverse =True)

print "-------------"

for i in range(0,len(b)):
	for j in range(0,b[i][1]):
		print b[i][0]
	
