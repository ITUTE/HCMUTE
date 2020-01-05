A=[]
n=int(input("n = "))
def inputArr(A,n):
    for i in range(n):
        A.append(int(input()))

inputArr(A,n)
print(A)
