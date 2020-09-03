import math

def GiaiPT_Bac2(a,b,c):
    delta = b*b - 4*a*c
    if (delta < 0):
        print("Phuong trinh vo nghiem!")
    elif (delta == 0):
        print("Phuong trinh co nghiem kep: x1 = x2 =", -b/(2*a))
    else:
        sqrt_delta = math.sqrt(delta)
        x1 = (-b - sqrt_delta)/(2*a)
        x2 = (-b + sqrt_delta)/(2*a)
        print("Phuong trinh co 2 nghiem:")
        print("x1 = ", x1, ";  x2 = ", x2)

a = int(input("Nhap a = "))
b = int(input("Nhap b = "))
c = int(input("Nhap c = "))

GiaiPT_Bac2(a,b,c)