n=int(input("n = "))

def findMaxDigit(n):
    x=n%10
    while (n):
        if (n%10 > x):
            x=n%10
        n=n//10
    return x

print("Ans: ", findMaxDigit(n))