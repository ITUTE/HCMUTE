 //https://github.com/Titytus/HCMUTE
 //-----Tinh a/b-----

#include <stdio.h>

void nhap(int &a, int &b);
int tinhThuong(int a, int b, float &thuong);
void xuat(int kt, float thuong);

int main()
{
	int a,b;
	nhap(a,b);
	float thuong;
	int kt=tinhThuong(a,b,thuong);
	xuat(kt,thuong);
	return 0;
}

void nhap(int &a, int &b)
{
	scanf("%d%d", &a, &b);
}

int tinhThuong(int a, int b, float &thuong)
{
	if (b==0)
		return 0;
	thuong = float(a) / b;
	return 1;
}
void xuat(int kt, float thuong)
{
	if (kt==0)
		printf("Khong chia duoc.");
	else
		printf("%.2f", thuong);	
}
