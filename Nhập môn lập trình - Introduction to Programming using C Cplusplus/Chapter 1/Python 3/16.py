a=float(input("Nhap a: "))
b=float(input("Nhap b: "))
c=float(input("Nhap c: "))

def laTamGiac(a,b,c):
    return (a>0 and b>0 and c>0 and a+b>c and b+c>a and a+c>b)
def laTGdeu(a,b,c):
    return (a==b==c)
def laTGcan(a,b,c):
    return (not(laTGdeu(a,b,c)) and (a==b or a==c or b==c))
def laTGvuong(a,b,c):
    return (a*a==b*b+c*c or b*b==a*a+c*c or c*c==a*a+b*b)
def laTGvuongcan(a,b,c):
    return (laTGvuong(a,b,c) and laTGcan(a,b,c))

if (laTamGiac(a,b,c)):
    if (laTGdeu(a,b,c)):
        print("Tam giác đều.")
    elif (laTGvuongcan(a,b,c)):
        print("Tam giác vuông cân.")
    elif (laTGvuong(a,b,c)):
        print("Tam giác vuông.")
    elif (laTGcan(a,b,c)):
        print("Tam giác cân.")
    else:
        print("Tam giác thường.")
else:
    print("Không phải tam giác.")