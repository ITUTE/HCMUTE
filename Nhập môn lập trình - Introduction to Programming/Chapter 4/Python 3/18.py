A=[int(x) for x in str(input("A: ")).split()]
A=[str(x) for x in A]
s=' '.join(A)
if (s.find("0 0")>=0): print("Yes")
else: print("No")