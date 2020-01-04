h=int(input("Nhập giờ: "))
m=int(input("Nhập phút: "))
s=int(input("Nhập giây: "))
if (h>=0 and m>=0 and s>=0 and h<24 and m<60 and s<60):
    print("Hợp lệ.")
else:
    print("Không hợp lệ.")
