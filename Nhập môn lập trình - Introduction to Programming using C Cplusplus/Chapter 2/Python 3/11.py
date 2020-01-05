n=int(input("n = "))

def reverseNum(n):
    x=0
    while (n):
        x=10*x+n%10
        n=n//10
    return x

def isPalindromeNum(n):
    return (n==reverseNum(n))

if (isPalindromeNum(n)):
    print(n," is palindrome number!")
else:
    print(n," isn't palindrome number.")