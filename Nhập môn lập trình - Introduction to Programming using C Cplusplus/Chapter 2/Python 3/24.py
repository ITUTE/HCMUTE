n=int(input("n = "))

def find(n):
    if (n%2==1): return n
    i=n-1
    while (i):
        if (n%i==0 and i%2==1): return i
        i-=1

print("Ước số lẻ lớn nhất: ", find(n))