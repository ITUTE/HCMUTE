import math
n=int(input("n = "))

def isSquareNum(n):
    return (int(math.sqrt(n))==math.sqrt(n))

def countSquareNum(n):
    c=0
    for i in range(0,n):
        if isSquareNum(i): c+=1
    return c

print("Number of square numbers: ", countSquareNum(n))