A=[int(x) for x in str(input("Input A: ")).split()]

def check(A):
    for i in A:
        if (i%2!=0): return 0
    return 1

print(check(A))