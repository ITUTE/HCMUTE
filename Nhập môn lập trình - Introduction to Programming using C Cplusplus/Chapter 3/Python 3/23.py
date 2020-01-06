A=str(input("Nhập mảng các số nguyên: ")).split(' ')
A=[int(i) for i in A]

def GCD(a,b):
    if (a<0): a=-a
    if (b<0): b=-b
    while (a*b):
        if (a>b): a=a%b
        else: b=b%a
    return a+b

def GCD_Array(A):
    x=A[0]
    for i in A:  x=GCD(i,x)
    return x

print(GCD_Array(A))