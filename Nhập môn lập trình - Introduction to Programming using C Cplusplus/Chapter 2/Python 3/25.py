n=int(input("n = "))

def sumP(n):
    s=0; p=1; sum=0
    for i in range(1,n+1): 
        p=p*i; s+=i
        sum+=s/p
    return sum

print("S = ", sumP(n))