//https://github.com/Titytus/HCMUTE
//-----Min(a,b,c)-----

#include <stdio.h>

void nhap(int &a, int &b, int &c);
void xuat(int a);
int min(int a, int b, int c);

int main()
{
	int a,b,c;
	nhap(a,b,c);
	int kq=min(a,b,c);
	xuat(kq);
}

void nhap(int &a, int &b, int &c)
{
	scanf("%d%d%d", &a, &b, &c);
}

void xuat(int a)
{
	printf("%d", a);
}

int min(int a, int b, int c)
{
	if ((a<=b)&&(a<=c))
		return a;
	if ((b<=a)&&(b<=c))
			return b;
	return c;
}
