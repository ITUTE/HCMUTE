n=int(input("n = "))

def countPrimeDigit(n):
    s=0
    while (n):
        if (n%10==2 or n%10==3 or n%10==5 or n%10==7):
            s+=1
        n=n//10
    return s

print("Count = ",countPrimeDigit(n))