print "Enter number of People"
n = input()
a = []
print "Enter Walking rate of peoples"
for i in range(0,n):
	x = input()
	a.append([x,i])

a.sort()
for i in range(0,n):
	print "People ",a[i][1],"with speed",a[i][0]
