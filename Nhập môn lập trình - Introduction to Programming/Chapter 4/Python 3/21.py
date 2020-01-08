A=[int(x) for x in str(input("Input A: ")).split()]

def foo(A):
    for i in range(0,len(A)-1):
        if (A[i]+A[i+1])%2==0: return 0
    return 1

print("Dãy số lẻ" if foo(A) else "Dãy không thỏa tính chất")