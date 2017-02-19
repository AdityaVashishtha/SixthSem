def power(x,y):
    if (y==0):
        return 1;
    elif (y%2==0):
        p = power(x,y/2)
        return p*p
    else:
        p = power(x,y/2)
        return x*p*p

print "Enter number to find Fibonacci"
n=input()
root5 = pow(5,0.5)
phi = (1+root5)/2
omega = (1-root5)/2

fibo = (power(phi,n)-power(omega,n))/root5
print fibo
