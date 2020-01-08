A=[float(x) for x in str(input("Input: ")).split()]
x=float(input("x = "))
y=float(input("y = "))

def listArr(A,x,y):
    B=[]
    for i in A:
        if (x<=i<=y): B.append(i)
    return B

print(listArr(A,x,y))