ch=input("Nhập một chữ cái: ")
if ('a'<=ch<='z'):
    print(chr(ord(ch)-32))
elif ('A'<=ch<='Z'):
    print(chr(ord(ch)+32))
else:
    print(ch)