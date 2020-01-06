n=int(input("n = "))

def foo(n):
    F=[]
    P=[100000,50000,20000,10000]
    for i in P:
        F.append(n//i)
        n=n%i
    return F

print(foo(n))