#include <stdio.h>
#define SIZE 1000

struct PHANSO
{
	int tu;
	int mau;
};

void nhapPS(PHANSO &ps);
void xuatPS(PHANSO ps);
void nhap(PHANSO A[], int &n);
void xuat(PHANSO A[], int n);
int UCLN(int x, int y);
int BCNN(int x, int y);
void rutGon(PHANSO &ps);
int ps_am(PHANSO ps);
void phanLoai(PHANSO A[], int n, int &am, int &duong);
int pos_first_duong(PHANSO A[], int n);
int soSanh(PHANSO x, PHANSO y);
void pos_first_minmax(PHANSO A[], int n, int &posMin, int &posMax);
void swapPS(PHANSO &x, PHANSO &y);
void increase(PHANSO A[], int n);
void decrease(PHANSO A[], int n);

int main()
{
	PHANSO A[SIZE];
	int n;
	nhap(A,n);
	xuat(A,n);
	return 0;
}

void nhapPS(PHANSO &ps)
{
	scanf("%d",&ps.tu);
	scanf("%d",&ps.mau);
}

void xuatPS(PHANSO ps)
{
	printf("%d %d",ps.tu,ps.mau);
}

void nhap(PHANSO A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		nhapPS(A[i]);
}

void xuat(PHANSO A[], int n)
{
	decrease(A,n);
	for (int i=0;i<n;i++)
	{
		rutGon(A[i]);
		xuatPS(A[i]);
		printf("\t");
	}
	int posMin, posMax;
	pos_first_minmax(A,n,posMin,posMax);
	printf("\n Min=");
	xuatPS(A[posMin]);
	printf("\n Max=");
	xuatPS(A[posMax]);
}

int UCLN(int x, int y)
{
	if (x==0||y==0)
		return x+y;
	if (x<0) x=-x;
	if (y<0) y=-y;
	while (x*y!=0)
		if (x>y)	x%=y;
		else		y%=x;
	return x+y;	
}	

int BCNN(int x, int y)
{
	if (x<0) x=-x;
	if (y<0) y=-y;
	return (x/UCLN(x,y))*y;
}

void rutGon(PHANSO &ps)
{
	int tmp=UCLN(ps.tu,ps.mau);
	if (ps.mau<0)
		tmp=-tmp;
	ps.tu/=tmp;
	ps.mau/=tmp;
}

void phanLoai(PHANSO A[], int n, int &am, int &duong)
{
	am=0;
	duong=0;
	for (int i=0;i<n;i++)
		if (ps_am(A[i]))
			am++;
		else duong++;
}

int ps_am(PHANSO ps)
{
	if (ps.tu*ps.mau<0)
		return 1;
	return 0;
}

int pos_first_duong(PHANSO A[], int n)
{
	int i;
	for (i=0;i<n;i++)
		if (!ps_am(A[i]))
			return i;
	if (i==n)
		return -1;
}

int soSanh(PHANSO x, PHANSO y)
{
	int tmp=BCNN(x.mau,y.mau);
	if (x.mau<0)
	{
		x.tu=-x.tu;
		x.mau=-x.mau;
	}
	if (y.mau<0)
	{
		y.tu=-y.tu;
		y.mau=-y.mau;
	}
	x.tu=(tmp/x.mau)*x.tu;
	y.tu=(tmp/y.mau)*y.tu;
	if (x.tu>y.tu)
		return 1;
	if (x.tu==y.tu)
		return 0;
	return -1;
}

void pos_first_minmax(PHANSO A[], int n, int &posMin, int &posMax)
{
	posMin=0;
	posMax=0;
	for (int i=0;i<n;i++)
		if (soSanh(A[i],A[posMax])==1)
			posMax=i;
		else if (soSanh(A[i],A[posMin])==-1)
			posMin=i;
	/*
	increase(A,n);
	posMin=0;
	posMax=n-1;*/
		
}

void swapPS(PHANSO &x, PHANSO &y)
{
	PHANSO tmp=x;
	x=y;
	y=tmp;
}

void increase(PHANSO A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (soSanh(A[i],A[j])==1)
				swapPS(A[i],A[j]);
}

void decrease(PHANSO A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (soSanh(A[i],A[j])==-1)
				swapPS(A[i],A[j]);			
}
