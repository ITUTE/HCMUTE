A=[int(x) for x in str(input("Input A: ")).split()]

def isPalindromeArray(A):
    for i in range(0,len(A)//2+1):
        if (A[i]!=A[len(A)-i-1]):   return 0
    return 1

print("Dãy đối xứng!" if isPalindromeArray(A) else "Dãy đã cho không đối xứng.")