import math
n=int(input("n = "))

def isSquareNum(n):
    return (int(math.sqrt(n))==math.sqrt(n))

def listSquareNum(n):
    listSqNum=[]
    for i in range(0,n):
        if isSquareNum(i):
            listSqNum.append(i)
    return listSqNum

print("List square numbers: ", listSquareNum(n))