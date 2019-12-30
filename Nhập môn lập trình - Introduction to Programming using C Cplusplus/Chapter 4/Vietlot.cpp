#include <stdio.h>
#define size 50
#define N 6

void nhapMang(int A[],int n);
int xuat(int kq);
int xuLy(int A[], int B[], int n);
int timThay(int A[], int n, int x);

int main()
{
	int A[size], B[size];
	nhapMang(A,N);
	nhapMang(B,N);
	int kq=xuLy(A,B,N);
	xuat(kq);
	return 0;
}

void nhapMang(int A[],int n)
{
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int xuat(int kq)
{
	printf("%d",kq);
}

int timThay(int A[], int n, int x)
{
	for (int i=0;i<n;i++)
		if (A[i]==x)
			return 1;
	return 0;
}

int xuLy(int A[], int B[], int n)
{
	int dem=0;
	for (int i=0;i<n;i++)
		if (timThay(B,n,A[i]))
			dem++;
	if (dem>=3)
		return N-dem;
	return -1;
}
