//https://github.com/Titytus/HCMUTE
//-----Giai phuong trinh ax+b=0 -----

#include <stdio.h>

void nhap(float &a, float &b);
int solve(float a, float b, float &x);
void xuat(int kt, float x);

int main()
{
	float a,b,x;
	nhap(a,b);
	int kt = solve(a,b,x);
	xuat(kt,x);
	return 0;
}

void nhap(float &a, float &b)
{
	scanf("%f%f", &a, &b);
}

int solve(float a, float b, float &x)
{
	if (a == 0)
	{
		if (b!=0)
			return 0;
		return 1;
	}
	x = - float(b)/a;
	return 2;
}
void xuat(int kt, float x)
{
	switch (kt)
	{
		case 0:
			printf("Phuong trinh vo nghiem.");	break;
		case 1:
			printf("Phuong trinh VSN");			break;
		case 2:
			printf("Nghiem duy nhat: x= %.2f", x);
	}
}
