A=[int(x) for x in str(input("A: ")).split()]
B=[int(x) for x in str(input("B: ")).split()]

def check(A,B):
    for x in A:
        if (x not in B):
            return 0
    return 1

if (check(A,B)): print("Yes")
else: print("No")
