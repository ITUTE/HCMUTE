m=int(input("Month: "))
y=int(input("Year: "))
def isLeapYear(y):
    if (y%400==0 or (y%4==0 and y%100!=0)):
        return 1
    return 0;
def DaysInMonth(month,year):
    A=[31,31,28,31,30,31,30,31,31,30,31,30,31]
    if (month!=2):
        return A[month]
    elif (isLeapYear(year)):
        return 29
    else:
        return 28
print("Days in this Month: ",DaysInMonth(m,y))