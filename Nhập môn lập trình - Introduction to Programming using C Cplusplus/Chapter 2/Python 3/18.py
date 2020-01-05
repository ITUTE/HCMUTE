n=int(input("n = "))

def isPerfectNum(n):
    c=0
    for i in range(1,n):
        if (n%i==0): c+=i
    if (c==n): return 1
    return 0

def countPerfectNum(n):
    c=0
    for i in range(1,n):
        if isPerfectNum(i): c+=1
    return c

print("Number of perfect numbers: ", countPerfectNum(n))