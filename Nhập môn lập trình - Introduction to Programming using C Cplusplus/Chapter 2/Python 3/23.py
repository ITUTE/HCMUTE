import math
n=int(input("n = "))

def isPrimeNum(n):
    if (n==2 or n==3): return 1
    if (n<2 or n%2==0 or n%3==0): return 0
    i=2; sqrtN=int(math.sqrt(n))
    while (i<=sqrtN):
        if (n%i==0): return 0
        i+=2
    return 1

def count(n):
    c=0
    for i in range(2,n//2+1):
        if (n%i==0 and isPrimeNum(i)): c+=1
    return c

print("Số ước nguyên tố: ", count(n))