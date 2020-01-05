n=int(input("n = "))

def isPerfectNum(n):
    c=0
    for i in range(1,n):
        if (n%i==0): c+=i
    if (c==n): return 1
    return 0

def listPerfectNum(n):
    A=[]
    for i in range(1,n):
        if isPerfectNum(i): A.append(i)
    return A

print("List perfect numbers: ", listPerfectNum(n))