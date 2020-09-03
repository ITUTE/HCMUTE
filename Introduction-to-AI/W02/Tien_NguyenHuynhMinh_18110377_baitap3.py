A = [1,3,7,0,-2,-34,3434]

def Sort(A):
    for i in range(0, len(A)-1):
        for j in range(i, len(A)):
            if (A[i] > A[j]):
                A[i], A[j] = A[j], A[i]
    return A

print("Mang sau khi sort:")
print(Sort(A))