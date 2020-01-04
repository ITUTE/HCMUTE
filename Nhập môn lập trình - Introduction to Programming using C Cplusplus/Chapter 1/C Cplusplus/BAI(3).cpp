//https://github.com/Titytus/HCMUTE
//-----Chu vi HCN-----

#include <stdio.h>

void nhap(double &a, double &b);
double tinh(double a, double b);
void xuat(double a);

int main()
{
	double a,b;
	nhap(a,b);
	double chuvi=tinh(a,b);
	xuat(chuvi);
	return 0;
}

void nhap(double &a, double &b)
{
	scanf("%lf%lf", &a, &b);
}

double tinh(double a, double b)
{
	return 2*(a+b);
}

void xuat(double a)
{
	printf("%.2lf", a);
}
