//https://github.com/Titytus/HCMUTE
//-----Tinh a+b-----

#include <stdio.h>

void nhap(int &a, int &b);
int sum(int a, int b);
void xuat(int x);

int main()
{
	int a,b;
	nhap(a,b);
	int kq=sum(a,b);
	xuat(kq);
	return 0;
}

void nhap(int &a, int &b)
{
	scanf("%d%d", &a, &b);
}

int sum(int a, int b)
{
	return a+b;
}

void xuat(int x)
{
	printf("%d",x);
}
