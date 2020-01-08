a=int(input("Nhập a: "))
b=int(input("Nhập b: "))
def cmp(a,b):
    return (a>b)-(a<b)
if (cmp(a,b)>0):
    print("Số lớn nhất: ", a)
else:
    print("Số lớn nhất: ", b)
