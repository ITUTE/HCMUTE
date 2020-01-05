n=int(input("n ="))
def sumGiaiThua(n):
    s=0
    p=1
    for i in range(1,n+1):
        p=p*i
        s=s+p
    return s

print("s =",sumGiaiThua(n))