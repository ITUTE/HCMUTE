a=int(input("a = "))
b=int(input("b = "))

def GCD(a,b):
    while (a*b):
        if (a>b): a=a%b
        else: b=b%a
    return a+b

print("USCLN(",a,",",b,") = ",GCD(a,b))