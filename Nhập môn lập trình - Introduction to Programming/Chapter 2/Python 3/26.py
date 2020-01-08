n=int(input("n = "))

def Fibonacci(n):
    F=[1,1]
    if (n<2): return F[:n+1]
    for i in range(2,n+1):  F.append(F[i-1]+F[i-2])
    return F

print(Fibonacci(n))