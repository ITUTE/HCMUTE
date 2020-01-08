A=[int(x) for x in str(input("Input A: ")).split()]
B=[int(x) for x in str(input("Input A: ")).split()]

OnlyA=[x for x in A if x not in B]
OnlyB=[x for x in B if x not in A]

print("Length of list OnlyA: ", len(OnlyA))
print("Length of list OnlyB: ", len(OnlyB))