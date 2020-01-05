h=int(input("Hour: "))
m=int(input("Min: "))
s=int(input("Sec: "))

def isValid(h,m,s):
    return (h>=0 and m>=0 and s>=0 and h<24 and m<60 and s<60)
def oneMinAfter(h,m,s):
    if (s==59):
        if (m==59):
            if (h==23):
                h=m=s=0;
            else:
                m=s=0;
                h=h+1
        else:
            s=0
            m=m+1
    else:
        s=s+1
    return h,m,s

if (isValid(h,m,s)):
    h,m,s=oneMinAfter(h,m,s)
    print(h,m,s)
else:
    print("Dữ liệu không hợp lệ!")
