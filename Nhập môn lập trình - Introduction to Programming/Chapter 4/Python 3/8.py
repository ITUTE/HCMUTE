A=[int(x) for x in str(input("Input: ")).split()]
x=int(input("x = "))
y=int(input("y = "))
B=[k for k in A if (x<=k<=y and k%2==0)]
print(B)