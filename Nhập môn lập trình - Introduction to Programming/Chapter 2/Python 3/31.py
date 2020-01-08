d1=str(input("Nhập ngày thứ nhất (dd/mm/yyyy): ")).split('/')
d2=str(input("Nhập ngày thứ hai (dd/mm/yyyy): ")).split('/')

A=[31,31,28,31,30,31,30,31,31,30,31,30,31]
def isLeapYear(n):
    if (n%400==0 or (n%4==0 and n%100!=0)):
        return 1
    return 0

def noYear(d):
    c=0; m=int(d[1])
    global A
    for i in range(1,m): c+=A[i]
    c+=int(d[0])
    if (int(d[1])>2 and isLeapYear(int(d[2]))): c+=1
    return c

def distance(d1,d2):
    c=noYear(d2); y1=int(d1[2]); y2=int(d2[2])
    for i in range(min(y1,y2)+1,max(y1,y2)):
        c+=365 + isLeapYear(i)
    c+=365+isLeapYear(int(d1[2]))-noYear(d1)
    return c

print("Khoảng cách 2 ngày: ", distance(d1,d2))