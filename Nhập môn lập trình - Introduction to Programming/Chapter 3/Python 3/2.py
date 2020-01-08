n=int(input("n= "))
A=[]
def inputArr(A,n):
    for i in range(n):
        A.append(float(input()))

def sumArr(A,n):
    s=0
    for i in A: s+=i
    return s

inputArr(A,n)
print(A)
print("Sum of array: ", sumArr(A,n))
