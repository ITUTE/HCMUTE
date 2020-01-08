A=[int(x) for x in str(input("Input A: ")).split()]

def foo(A):
    for i in range(1,len(A)-1):
        if not(A[i-1]<A[i]<A[i+1]) or not(A[i-1]>A[i]>A[i+1]):
            return 0
    return 1

print("Đây là dãy số dạng sóng" if foo(A) else "Không phải dãy dạng sóng")