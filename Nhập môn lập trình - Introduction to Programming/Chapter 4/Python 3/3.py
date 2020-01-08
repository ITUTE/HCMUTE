n=int(input("n = "))
A=[]
for i in range(0,n): A.append(int(input()))

def findMax2nd(A):
    max=x=0
    for i in range(1,len(A)):
        if (A[i]>A[max]):
            x=max; max=i
    return x

print("Pos(max2nd) = ", findMax2nd(A))