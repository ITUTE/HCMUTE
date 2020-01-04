import math
print("aX^2 + bX + c = 0")
a=float(input("a="))
b=float(input("b="))
c=float(input("c="))
if (a==0):
    if (b==0):
        if (c==0):
            print("Phương trình có vô số nghiệm")
        else:
            print("Phương trình có 0 nghiệm")
    else:
        print("Phương trình có 1 nghiệm: ", -c/b)
else:
    