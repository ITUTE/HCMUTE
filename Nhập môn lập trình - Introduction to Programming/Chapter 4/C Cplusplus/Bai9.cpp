#include <stdio.h>
#include <math.h>
#define size 32000

void nhapMang(int A[], int &n);
void xuly(int A[], int B[], int n);
void xuat(int A[], int B[], int n);

int main()
{
	int A[size], B[size], n;
	nhapMang(A,n);
	xuly(A,B,n);
	xuat(A,B,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuly(int A[], int B[], int n)
{
	for (int i=0;i<n-1;i++)
		if (A[i]>abs(A[i+1]))
		//dung B[] de danh dau vi tri trong A[]
			B[i]=1;
}

void xuat(int A[], int B[], int n)
{
	for (int i=0;i<n;i++)
		if (B[i]==1)
			printf("%d ",A[i]);
}
