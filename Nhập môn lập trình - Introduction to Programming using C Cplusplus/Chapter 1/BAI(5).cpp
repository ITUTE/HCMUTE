//https://github.com/Titytus/HCMUTE
//-----Kiem tra gia tri hh:mm:ss-----

#include <stdio.h>

void nhap(int &h, int &m, int &s);
bool kiemtra(int h, int m, int s);
void xuat(bool a);

int main()
{
	int h,m,s;
	nhap(h,m,s);
	bool kq=kiemtra(h,m,s);
	xuat(kq);
	return 0;
}

void nhap(int &h, int &m, int &s)
{
	scanf("%d%d%d", &h, &m, &s);
}

bool kiemtra(int h, int m, int s)
{
	return ((h>=0)&&(h<24) && (m>=0)&&(m<60) && (s>=0)&&(s<60));
}

void xuat(bool a)
{
	if (a)
		printf("Hop le");
	else
		printf("Khong hop le");
}
