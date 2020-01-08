n=int(input("n= "))
A=[]
def inputArr(A,n):
    for i in range(n):
        A.append(int(input()))

def max(A,n):
    x=A[0]
    for i in A:
        if (i>x): x=i
    return x

inputArr(A,n)
print(A)
print("Max of array: ", max(A,n))