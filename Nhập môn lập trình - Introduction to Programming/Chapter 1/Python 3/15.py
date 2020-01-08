a=int(input("a="))
b=int(input("b="))
c=int(input("c="))
def findMin2nd(a,b,c):
    if (a<b):
        if (b<c):
            return b
        elif (a<c):
            return c
        else:
            return a
    else:
        if (a<c):
            return a
        elif (b<c):
            return c
        else:
            return b
print("Min2nd = ", findMin2nd(a,b,c))
