n=int(input("n = "))

def reverseNum(n):
    x=0
    while (n):
        x=10*x+n%10
        n=n//10
    return x

print("ReverseNum: ", reverseNum(n))