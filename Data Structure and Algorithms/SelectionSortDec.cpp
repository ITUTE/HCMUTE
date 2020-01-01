#include <stdio.h>
void swap(int &a, int &b);
void SelectionSort(int A[], int n);
void Xuat(int A[], int n);

int main()
{
	int A[]={1,6,0,2,4,8,3,5,7,9};
	int n=10;
	SelectionSort(A,n);
	Xuat(A,n);
	return 0;
}

void SelectionSort(int A[], int n)
{
	for (int i=0;i<n-1;i++)
	{
		int posMin=i;
		for (int j=i+1;j<n;j++)
			if (A[j]>A[posMin])
				posMin=j;
		swap(A[i],A[posMin]);
	}
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
