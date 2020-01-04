a=int(input("a= "))
b=int(input("b= "))
c=int(input("c= "))
if (a>0 and b>0 and c>0):
    if (a+b>c and b+c>a and a+c>b):
        print("Tam giác hợp lệ.")
    else:
        print("Không phải tam giác.")
else:
    print("Độ dài cạnh không hợp lệ.")
