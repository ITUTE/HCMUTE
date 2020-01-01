#include <stdio.h>
void InterchangeSort(int A[], int n);
void swap(int &a, int &b);
void Xuat(int A[], int n);

int main()
{
	int A[]={5,1,7,9,2,3,0,8,4,6};
	int n=10;
	InterchangeSort(A,n);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void InterchangeSort(int A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (A[i]>A[j])
				swap(A[i],A[j]);
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
