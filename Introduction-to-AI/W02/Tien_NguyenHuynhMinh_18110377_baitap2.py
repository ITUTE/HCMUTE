n = -1
while (n < 0):
    n = int(input("Nhap n (n>=0): "))

def GiaiThua(n):
    re = 1
    for i in range (1,n+1):
        re = re * i
    return re

print(n, "! = ", GiaiThua(n))