import math
n=int(input("n = "))
x=float(input("x = "))

def foo(n,x):
    s=0
    for i in range(1,n+1):
        s=math.sqrt(x+s)
    return s

print("S = ", foo(n,x))