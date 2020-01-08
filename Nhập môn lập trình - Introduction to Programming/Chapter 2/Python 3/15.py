n=int(input("n = "))

def cmp(a,b):
    return (a>b)-(b>a)

def check(n, sign=1):
    while (n//10):
        if (cmp(n%10,(n//10)%10)==sign):
            return 0
        n=n//10
    return 1

if (check(n,-1) or check(n,1)):
    print("Các chữ số của ", n, " nhất biến!")
else:
    print("Số ", n, " không thỏa điều kiện")