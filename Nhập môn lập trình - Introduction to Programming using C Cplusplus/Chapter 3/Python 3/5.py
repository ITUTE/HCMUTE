n=int(input("n= "))
A=[]
def inputArr(A,n):
    for i in range(n):
        A.append(int(input()))

def sumif(A,n):
    s=0; count=0
    for i in A: 
        if (i%5==0):
            s+=i; count+=1
    return s/count

inputArr(A,n)
print(A)
print("Ans: ", sumif(A,n))
