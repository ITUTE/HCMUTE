#include<stdio.h>
#define SIZE 100
void xuatMang(int A[], int n);
void nhapMang(int A[], int n);
void xoaViTriK(int A[], int &n, int k);
void themViTriK(int A[], int &n, int x, int k);
void xoayMang(int A[], int n, int k);
void nhap(int &x);
int main()
{
	int A[SIZE],n,k;
	nhap(n);
	nhap(k);
	nhapMang(A,n);
	xoayMang(A,n,k);
	xuatMang(A,n);
}
void xoayMang(int A[], int nA, int k)
{
	int B[SIZE], nB,i;
	nB = 0;
	for (i=k;i<nA;i++)
		B[nB++] = A[i];
	for (i=0;i<k;i++)
		B[nB++] = A[i];
	for (i=0;i<nA;i++)
		A[i] = B[i];
}
/*
void xoayMang(int A[], int n, int k)
{
	for (int i=0;i<k;i++)
	{
		int x = A[0];
		xoaViTriK(A,n,0);
		themViTriK(A,n,x,n);
	}
}
void themViTriK(int A[], int &n, int x, int k)
{
	for (int i=n; i>k; i--)
		A[i]=A[i-1];
	A[k]=x;
	n++;
}
void xoaViTriK(int A[], int &n, int k)
{
	for (int i = k; i<n-1; i++)
		A[i] = A[i+1];
	n--;
}
*/
void nhap(int &x)
{
	scanf("%d",&x);
}
void nhapMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
void xuatMang(int A[], int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
}
