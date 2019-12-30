//https://github.com/Titytus/HCMUTE
//----- IN: 3.2 >> OUT: 3;  IN:-3.2 >> OUT: -4 -----
#include <stdio.h>

void nhap(double &a);
void xuat(int kq);
int xuly(double a);

int main()
{
	double a;
	nhap(a);
	int kq=xuly(a);
	xuat(kq);
	return 0;
}

void nhap(double &a)
{
	scanf("%lf",&a);
}

void xuat(int kq)
{
	printf("%d",kq);
}

int xuly(double a)
{
	if (a<0)
		return (int)a - 1;
	return (int)a;
}
