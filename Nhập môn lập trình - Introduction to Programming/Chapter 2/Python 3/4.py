n=int(input("Nhập n = "))
def GiaiThua(n):
    s=1
    for i in range(1,n+1):
        s=s*i
    return s

print("S = ", GiaiThua(n))