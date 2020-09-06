
//-----abs(n)-----

#include <stdio.h>

void nhap(int &n);
int abs(int n);
void xuat(int kq);

int main()
{
	int n;
	nhap(n);
	int giatri=abs(n);
	xuat(giatri);
	return 0;
}

void nhap(int &n)
{
	scanf("%d", &n);
}

int abs(int n)
{
	if (n<0)
		return -n;
	return n;
}

void xuat(int kq)
{
	printf("%d", kq);
}
