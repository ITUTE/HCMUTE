n=int(input("n = "))
x=float(input("x = "))

def sumif(n,x):
    s=1; frac=1
    for i in range(1,n+1):
        frac=frac*(x/i)
        s+=frac
    return s

print("S = ", sumif(n,x))