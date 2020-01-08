A=[int(x) for x in str(input("Input A: ")).split()]

def CSC(A):
    d=A[1]-A[0]
    for i in range(2,len(A)):
        if (A[i]-A[i-1]!=d):
            return False, d
    return True, d

check, d = CSC(A)
if (check): print("Công sai d =", d)
else: print("Không phải cấp số cộng")