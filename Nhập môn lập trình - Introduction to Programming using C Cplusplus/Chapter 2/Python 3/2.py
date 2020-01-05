n=int(input("Nhập n = "))
def sumN(n):
    s=0
    for i in range(1,n+1):
        s+=i*i
    return s

print("S = ", sumN(n))