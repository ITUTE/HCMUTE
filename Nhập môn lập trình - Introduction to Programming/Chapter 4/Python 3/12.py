A=[int(x) for x in str(input("A: ")).split()]
def sumCucTri(A):
    A=list(A)
    c=0
    if (A[0]!=A[1]): c=A[0]
    for i in range(1,len(A)-1):
        if (A[i]-A[i-1])*(A[i]-A[i+1])>0:
            c+=A[i]
    if (A[len(A)-1]!=A[len(A)-2]): c+=A[len(A)-1]
    return c

print(sumCucTri(A))