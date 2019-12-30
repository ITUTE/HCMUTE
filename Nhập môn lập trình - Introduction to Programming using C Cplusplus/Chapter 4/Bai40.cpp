#include <stdio.h>
#define size 100

void nhapMang(int A[], int &n);
void reverseBubbleSort(int A[], int n);
void swap(int &a, int &b);
void xuatMang(int A[], int n);

int main()
{
	int A[size],n,start=0,end=1;
	nhapMang(A,n);
	reverseBubbleSort(A,n);
	xuatMang(A,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void reverseBubbleSort(int A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (A[i]<A[j])
				swap(A[i],A[j]);
}

void swap(int &a, int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
