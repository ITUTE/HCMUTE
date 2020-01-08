A=[int(x) for x in str(input("Input A: ")).split()]
B=[int(x) for x in str(input("Input B: ")).split()]
print(any(A==B[i:i+len(A)] for i in range(len(B)-len(A)+1)))