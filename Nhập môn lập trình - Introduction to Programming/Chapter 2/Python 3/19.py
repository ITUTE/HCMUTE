import math
n=int(input("n = "))

def isPrime(n):
    if (n==2 or n==3): return 1
    if (n<2 or n%2==0 or n%3==0): return 0
    sqrtN=int(math.sqrt(n))
    for i in range(2,sqrtN+1):
        if (n%i==0): return 0
    return 1

def countPrime(n):
    c=0
    for i in range(2,n+1):
        if isPrime(i):  c+=1
    return c

print("Number of prime numbers: ", countPrime(n))