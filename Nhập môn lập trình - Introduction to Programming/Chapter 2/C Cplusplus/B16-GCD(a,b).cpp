//------UCLN(a,b)-----

#include <stdio.h>

void nhap(int &a, int &b);
int GCD(int a, int b);
void xuat(int kq);

int main()
{
	int a,b;
	nhap(a,b);
	int kq=GCD(a,b);
	xuat(kq);
	return 0;
}

void nhap(int &a, int &b)
{
	scanf("%d%d", &a, &b);
}

int GCD(int a, int b)
{
	if (a<0)	a=-a;
	if (b<0)	b=-b;
	while (a*b!=0)
		if (a>b)
			a%=b;
		else
			b%=a;
	//KQ cuoi cung: hoac a==0 hoac b==0
	return a+b;
}

/*
//Cach 2
int GCD(int a, int b)
{
	int x=1;
	int start;
	if (a<b) start=a;
	else
		if (a>b) start=b;
		else return a;
	for (int i=start; i>=1; i--)
		if ((a%i==0)&&(b%i==0)) return i;
}
*/

void xuat(int kq)
{
	printf("%d", kq);
}
