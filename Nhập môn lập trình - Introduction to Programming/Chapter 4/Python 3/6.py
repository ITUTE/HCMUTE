A=[float(x) for x in str(input("Input A: ")).split()]
B=[float(x) for x in str(input("Input A: ")).split()]

OnlyA=[x for x in A if x not in B]
BothAB=[x for x in A if x in B]

print(OnlyA)
print(BothAB)