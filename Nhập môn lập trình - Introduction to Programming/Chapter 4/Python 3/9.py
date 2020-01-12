A=[int(x) for x in str(input("A: ")).split()]
for i in range(1,len(A)):
    if (A[i-1]>abs(A[i])): print(A[i-1],end=" ")