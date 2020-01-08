A=[int(x) for x in str(input("Nhập mảng A: ")).split()]

def seperate(A):
    B=[]; C=[]
    for x in A:
        if (x>=0):  B.append(x)
        else:       C.append(x)
    return B,C

B=[]; C=[]
B,C=seperate(A)
print(B)
print(C)