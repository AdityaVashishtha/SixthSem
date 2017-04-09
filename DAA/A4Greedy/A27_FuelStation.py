def stopAtEvery(st,C,F,R):
	C = float(C)
	F = float(F)
	R = float(R)
	time = float(0)
	old = float(0)
	for i in range(0,len(st)):		
		new = st[i]
		km = st[i]-old		
		if (C >= km/F ):
			time = time + R*(km/F)
		else:
			print "Distance is more farther than it appear"
			break
		old = st[i]
	print "Time when we stop at every station",time
		
def fullAtStation(st,C,F,R):
	C = float(C)
	F = float(F)
	R = float(R)
	time = R*C
	old = float(0)
	fuelStatus = C
	for i in range(0,len(st)):
		new = st[i]
		km = st[i]-old	
		if fuelStatus < (km/F):
			neededFuel = C-fuelStatus
			#print "Needed Fuel", neededFuel,fuelStatus,km,km/F
			time = time + R*(neededFuel)
			fuelStatus = C			
		fuelStatus = fuelStatus - (km/F)
		old = st[i]
	
	print "Time when we Do not i say do not stop at every station",time
	
	

print "Enter Capacity of your CAR"
C=input()
print "Enter Mileage"
F=input()
print "Rate of Fuel Filling"
R=input()
print "Enter Stations"
a=[int(x) for x in raw_input().strip().split()]
a.sort()
stopAtEvery(a,C,F,R)
fullAtStation(a,C,F,R)

