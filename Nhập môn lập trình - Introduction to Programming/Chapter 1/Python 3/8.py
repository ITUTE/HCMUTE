a=float(input("a="))
def round(a):
    if (a>=0):
        return int(a)
    return int(a)-1
print("Round(",a,")=",round(a))
