import math
n=int(input("n = "))

def isPrime(n):
    if (n==2 or n==3):
        return 1
    if (n<2 or n%2==0 or n%3==0):
        return 0
    i=2; sqrtN=math.sqrt(n)
    while (i<=sqrtN):
        if (n%i==0):
            return 0
        i+=2
    return 1

if (isPrime(n)):
    print(n," is prime number!")
else:
    print(n," isn't prime number.")