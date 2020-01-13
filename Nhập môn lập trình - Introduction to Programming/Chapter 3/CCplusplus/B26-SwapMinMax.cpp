#include <stdio.h>
#define maxArr 1000

void nhap(int A[], int &n);
void xuat(int A[], int n);
void find(int A[], int n, int &max, int &min);
void swap(int A[], int max, int min);

int main()
{
	int n,A[maxArr],min,max;
	nhap(A,n);
	find(A,n,max,min);
	swap(A,max,min);
	xuat(A,n);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void find(int A[], int n, int &max, int &min)
{
	max=min=A[0];
	for (int i=0;i<n;i++)
		if (A[i]>A[max]) max=i;
		else 
			if (A[i]<A[min]) min=i;
}

void swap(int A[], int max, int min)
{
	int t=A[max];
	A[max]=A[min];
	A[min]=t;
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ", A[i]);
}
