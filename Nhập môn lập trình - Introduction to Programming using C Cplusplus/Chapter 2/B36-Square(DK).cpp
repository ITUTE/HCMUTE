#include <stdio.h>
#include <math.h>

void nhap(int &n, float &x);
float solve(int n, float x);
void xuat(float kq);

int main()
{
	int n;
	float x;
	nhap(n,x);
	float kq=solve(n,x);
	xuat(kq);
	return 0;
}

void nhap(int &n,float &x)
{
	scanf("%d%f", &n,&x);
}

float solve(int n, float x)
{
	float s=0;
	for (int i=1;i<=n;i++)
		s=sqrt(x+s);
	return s;
}

void xuat(float kq)
{
	printf("%f", kq);
}
