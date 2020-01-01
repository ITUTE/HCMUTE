#include <stdio.h>
void Xuat(int A[], int n);
void swap(int &a, int &b);
void BubbleSort(int A[], int n);

int main()
{
	int A[]={1,8,6,2,0,4,7,9,3,5};
	int n=10;
	BubbleSort(A,n);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void BubbleSort(int A[], int n)
{
	for (int i=0;i<n;i++)
		for (int j=n-1;j>i;j--)
			if (A[j]<A[j-1])
				swap(A[j],A[j-1]);
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
