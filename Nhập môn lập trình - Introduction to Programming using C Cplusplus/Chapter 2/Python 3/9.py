a=int(input("a = "))
b=int(input("b = "))
n=int(input("n = "))

def sumif(a,b,n):
    s=0
    for i in range (1,n):
        if (i%a==0 and i%b!=0):
            s+=i
    return s

print("s = ", sumif(a,b,n))