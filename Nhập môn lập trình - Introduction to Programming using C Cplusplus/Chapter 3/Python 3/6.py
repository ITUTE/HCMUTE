import math
n=int(input("n= "))
A=[]

def inputArr(A,n):
    for i in range(n):
        A.append(int(input()))

def isPrime(n):
    if (n==2 or n==3):
        return 1
    if (n<2 or n%2==0 or n%3==0):
        return 0
    i=2; sqrtN=math.sqrt(n)
    while (i<=sqrtN):
        if (n%i==0): return 0
        i+=2
    return 1

def countPrime(A,n):
    c=0
    for i in A:
        if (isPrime(i)): c+=1
    return c

inputArr(A,n)
print(A)
print("Number of primes: ", countPrime(A,n))