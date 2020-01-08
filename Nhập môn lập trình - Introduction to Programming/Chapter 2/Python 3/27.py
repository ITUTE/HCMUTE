n=int(input("n = "))

def Factor(n):
    i=2
    while (n>1):
        c=0
        while (n%i==0):
            c+=1
            n=n//i
        if (c):
            if (c>1): print(i,"^",c," . ",end='')
            else: print(i," . ",end='')
        i+=1

Factor(n)