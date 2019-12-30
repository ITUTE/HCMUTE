//-----UCLN(A[0],A[1],...,A[n-1])-----

#include <stdio.h>
#define max 32000

void nhap(int A[], int &n);
int GCD(int a, int b);
int GCDarr(int A[], int n);
void xuat(int kq);

int main()
{
	int n,A[max];
	nhap(A,n);
	int kq=GCDarr(A,n);
	xuat(kq);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

int GCD(int a, int b)
{
	if (a<0) a=-a;
	if (b<0) b=-b;
	while (a*b!=0)
	{
		if (a>b) a%=b;
		else b%=a;
	}
	return a+b;
}

int GCDarr(int A[], int n)
{
	int UCLN=A[0];
	for (int i=1;i<n;i++)
		UCLN=GCD(UCLN,A[i]);
	return UCLN;
}

void xuat(int kq)
{
	printf("%d",kq);
}
