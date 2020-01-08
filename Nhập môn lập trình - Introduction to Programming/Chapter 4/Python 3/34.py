A=[int(x) for x in str(input("Input A: ")).split()]

def isIncrease(A):
    for i in range(1,len(A)):
        if (A[i]<A[i-1]): return 0
    return 1

def foo(A):
    C=[]
    for i in range(0,len(A)):
        for j in range(i,len(A)):
            if isIncrease(A[i:j+1]): C.append(A[i:j+1])
    return C

print(foo(A))