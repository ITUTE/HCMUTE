n=int(input("n= "))
A=[]

def inputArr(A,n):
    for i in range(n):
        A.append(int(input()))

def maxif(A,n):
    x=0
    for i in A:
        if (i>x and i<0) : x=i
    if (x==0): return -1
    return x

inputArr(A,n)
print(A)
print("Số âm lớn nhất trong mảng: ", maxif(A,n))