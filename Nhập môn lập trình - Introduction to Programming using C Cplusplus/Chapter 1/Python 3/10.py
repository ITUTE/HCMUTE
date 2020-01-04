y=int(input("Year: "))
def isLeapYear(y):
    if (y%400==0 or (y%4==0 and y%400!=0)):
        return 1
    return 0
if (isLeapYear(y)):
    print(y," là năm nhuận")
else:
    print(y," không phải năm nhuận")
