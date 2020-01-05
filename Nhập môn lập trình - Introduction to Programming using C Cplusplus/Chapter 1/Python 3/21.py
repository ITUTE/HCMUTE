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
    delta=b*b-4*a*c;
    if (delta<0):
        print("Phương trình có 0 nghiệm")
    elif (delta==0):
        print("Phương trình có 1 nghiệm kép: ", -b/(2*a))
    else:
        print("Phương trình có 2 nghiệm:")
        x1=(-b-math.sqrt(delta))/(2*a)
        x2=(-b+math.sqrt(delta))/(2*a)
        print("x1=",x1)
        print("x2=",x2)