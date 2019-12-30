//https://github.com/Titytus/HCMUTE
//-----Max(a,b,c,d)-----

#include <stdio.h>

void nhap(float &a, float &b, float &c, float &d);
float max(float x, float y);
void xuat(float kq);

int main()
{
	float a,b,c,d;
	nhap(a,b,c,d);
	float kq=max(max(max(a,b),c),d);
	xuat(kq);
	return 0;
}

void nhap(float &a, float &b, float &c, float &d)
{
	scanf("%f%f%f%f", &a, &b, &c, &d);
}

float max(float x, float y)
{
	return (x>y) ? x : y;
}

void xuat(float kq)
{
	printf("%f", kq);
}

