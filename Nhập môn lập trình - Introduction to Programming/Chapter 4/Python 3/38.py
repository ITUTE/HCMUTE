A=[int(x) for x in str(input("Input A: ")).split()]
B=[int(x) for x in str(input("Input B: ")).split()]

def foo(A,B):
    c=0; nA=len(A); nB=len(B)
    for i in range(0,nB-nA+1,nA):
        if A==B[i:i+nA]: c+=1
    return c

print("Count = ", foo(A,B))