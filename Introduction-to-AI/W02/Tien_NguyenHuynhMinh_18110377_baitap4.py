import numpy as np

A = np.array([1,8,3,12,-3,-43,5,23])

def Sort(A, sapXepTang):
    #Sap xep tang theo mac dinh
    for i in range(0, A.size - 1):
        for j in range(i, A.size):
            if (A[i] > A[j]):
                A[i], A[j] = A[j], A[i]
    #Truong hop sap xep tang
    if (sapXepTang == 1):
        return A
    #Truong hop sap xep giam --> Reverse 
    return A[::-1]

print("Sap xep tang: ", Sort(A,1))
print("Sap xep giam: ", Sort(A,0))