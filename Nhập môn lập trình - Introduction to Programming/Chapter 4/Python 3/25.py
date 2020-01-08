import collections
A=[float(x) for x in str(input("Input: ")).split()]
maxValue=max(A)
A=[x for x in A if x!=maxValue]
print(A)