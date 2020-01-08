a=int(input("a="))
b=int(input("b="))
c=int(input("c="))
def min(a,b):
    if (a<b):
        return a
    return b
print("Số nhỏ nhất: ",min(min(a,b),c))

