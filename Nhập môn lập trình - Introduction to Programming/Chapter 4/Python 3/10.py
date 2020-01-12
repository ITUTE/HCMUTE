A=[int(x) for x in str(input("A: ")).split()]
if (A[0]*A[1]<0): print(A[0],end=" ")
for i in range(1,len(A)-1):
    if (A[i]*A[i-1]<0 or A[i]*A[i+1]<0):
        print(A[i],end=" ")
if (A[len(A)-1]*A[len(A)-2]<0): print(A[len(A)-1])