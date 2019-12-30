//https://github.com/Titytus/HCMUTE
//-----Lam tron-----

#include <stdio.h>
#include <math.h>

void nhap(float &a);
void xuat(int a);

int main()
{
	float a;
	nhap(a);
	xuat(roundf(a));
	return 0;
}

void nhap(float &a)
{
	scanf("%f", &a);
}

void xuat(int a)
{
	printf("%d", a);
}
