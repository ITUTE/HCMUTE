import math
n=int(input("n = "))

def isPrime(n):
    if (n==2 or n==3): return 1
    if (n<2 or n%2==0 or n%3==0): return 0
    sqrtN=int(math.sqrt(n))
    for i in range(2,sqrtN+1):
        if (n%i==0): return 0
    return 1

def listPrime(n):
    Prime=[]
    for i in range(2,n+1):
        if isPrime(i):  Prime.append(i)
    return Prime

print(listPrime(n))