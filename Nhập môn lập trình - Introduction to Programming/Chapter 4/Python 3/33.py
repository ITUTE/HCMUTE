A=[int(x) for x in str(input("Input A: ")).split()]

def foo(A):
    C=[]
    for i in range(0,len(A)):
        for j in range(i+1,len(A)):
            C.append(A[i:j+1])
    return C

print(foo(A))