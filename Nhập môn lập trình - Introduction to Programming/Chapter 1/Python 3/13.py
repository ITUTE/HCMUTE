a=int(input("a="))
b=int(input("b="))
c=int(input("c="))
d=int(input("d="))
def max(a,b):
    if (a>b):
        return a
    return b
print("Max=",max(max(max(a,b),c),d))
