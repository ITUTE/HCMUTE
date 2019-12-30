#include <stdio.h>
#define max 32000

void nhap(int A[], int &n);
void xuat(int A[], int n);

int main()
{
	int n, A[max];
	nhap(A,n);
	xuat(A,n);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ", A[i]);
}
