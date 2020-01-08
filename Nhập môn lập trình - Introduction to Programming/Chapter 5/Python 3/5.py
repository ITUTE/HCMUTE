s=str(input("s = ")).strip()
i=0
while (i<len(s)-1):
    if (s[i]==' '):
        j=i
        while (s[j]==' '): j+=1
        if (j-i>1): s=s[:i]+s[j-1:]
    i=i+1
print(s)
print(len(s))