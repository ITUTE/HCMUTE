print("aX + b = 0")
a=float(input("a="))
b=float(input("b="))
if (a==0):
    if (b==0):
        print("Phương trình có vô số nghiệm")
    else:
        print("Phương trình có 0 nghiệm")
else:
    print("Phương trình có 1 nghiệm: ", -b/a)