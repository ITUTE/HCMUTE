n=int(input("n = "))

def check(n):
    while (n):
        if ((n%10)%2==1):
            return 0
        n=n//10
    return 1

if (check(n)):
    print(n," chứa toàn số chẵn!")
else:
    print(n," có chứa số lẻ!")