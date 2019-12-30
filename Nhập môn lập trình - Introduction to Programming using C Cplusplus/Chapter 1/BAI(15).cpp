//https://github.com/Titytus/HCMUTE
//-----Min_2nd(a,b,c)-----

#include <stdio.h>

void nhap(int &a, int &b, int &c);
int min2nd(int a, int b, int c);
void xuat(int a);
int min(int a, int b);
int max(int a, int b);

int main()
{
	int a,b,c;
	nhap(a,b,c);
	int kq=min2nd(a,b,c);
	xuat(kq);
	return 0;
}

void nhap(int &a, int &b, int &c)
{
	scanf("%d%d%d", &a, &b, &c);
}

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int min(int a, int b)
{
	return (a>b) ? b : a;
}

int min2nd(int a, int b, int c)
{
	int m=min(min(a,b),c);
	int M=max(max(a,b),c);
	if (a!=m && a!=M)	return a;
	if (b!=m && b!=M)	return b;
	if (c!=m && c!=M)	return c;
}

void xuat(int a)
{
	printf("%d", a);
}
