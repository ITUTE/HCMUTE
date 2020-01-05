import math
n=int(input("n = "))
def isSquareNum(n):
    return (math.sqrt(n)**2==n)

if (isSquareNum(n)):
    print(n," is square number!")
else:
    print(n," isn't square number.")