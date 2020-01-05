n=int(input("n = "))

def isPerfectNum(n):
    s=0
    for i in range(1,n):
        if (n%i==0):
            s+=i
    if (s==n):
        return 1
    return 0

if (isPerfectNum(n)):
    print(n," is perfect number!")
else:
    print(n," isn't perfect number.")