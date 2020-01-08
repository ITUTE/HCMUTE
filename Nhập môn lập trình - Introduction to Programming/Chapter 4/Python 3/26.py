import math
A=[int(x) for x in str(input("Input: ")).split()]
A=[x for x in A if math.sqrt(x)!=int(math.sqrt(x))]
print(A)