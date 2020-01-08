import collections
A=[int(x) for x in str(input("Input: ")).split()]
A=[x for x,count in collections.Counter(A).items() if count==1]
print(A)