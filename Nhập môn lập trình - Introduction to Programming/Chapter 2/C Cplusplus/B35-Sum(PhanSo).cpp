//-----Tong 2 phan so-----

#include <stdio.h>

void nhap(int &tu, int &mau);
int ucln(int a,int b);
void solve(int a, int b, int c, int d, int &tu, int &mau);
void xuat(int tu, int mau);

int main()
{
	int a,b,c,d;
	nhap(a,b);
	nhap(c,d);
	int tu,mau;
	solve(a,b,c,d,tu,mau);
	xuat(tu,mau);
	return 0;
}

void nhap(int &tu, int &mau)
{
	scanf("%d%d", &tu,&mau);
}

void xuat(int tu, int mau)
{
	if (mau==1)
		printf("%d",tu);
	else
		printf("%d/%d",tu,mau);
}

int ucln(int a, int b)
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

void solve(int a, int b, int c, int d, int &tu, int &mau)
{
	tu=a*d+b*c;
	mau=b*d;
	int x=ucln(tu,mau);
	tu/=x;
	mau/=x;
}
