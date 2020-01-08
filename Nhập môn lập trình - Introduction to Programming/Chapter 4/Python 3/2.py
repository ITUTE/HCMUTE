A = [int(i) for i in str(input("Nhập mảng A: ")).split()]
B = [int(i) for i in str(input("Nhập mảng B: ")).split()]

def mergeArray(A,B):
    i=0; j=0
    C=[]
    while (i<len(A) and j<len(B)):
        try:
            while (i<len(A) and A[i]<B[j]):
                C.append(A[i]); i+=1
            while (j<len(B) and B[j]<A[i]):
                C.append(B[j]); j+=1
        except:
            if (i<len(A)):
                for x in A[i:]: C.append(x)
            if (j<len(B)):
                for x in B[j:]: C.append(x)
    return C

print(mergeArray(A,B))