#include <stdio.h>
void swap(int &a, int &b);
void Xuat(int A[], int n);
void Heap(int A[], int i, int n);
void HeapSort(int A[], int n);

int main()
{
	int A[]={5,3,6,1,9,2,4,0,8,7};
	int n=10;
	HeapSort(A,n);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void PrintHeap(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n\n");
}
void HeapSort(int A[], int n)
{
	for (int i=n/2;i>=0;i--)
		Heap(A,i,n);
	PrintHeap(A,n);
	for (int i=n-1;i>=0;i--)
	{
		swap(A[0],A[i]);
		Heap(A,0,i);
		PrintHeap(A,i);
	}
}

void Heap(int A[], int i, int n)
{
	int j=i;
	while (2*j<n)
	{
		int t=2*j;
		if (2*j+1<n)
		{
			if (A[2*j+1]>=A[2*j])
				t=2*j+1;
		}
		if (A[t]>A[j])
		{
			swap(A[t],A[j]);
			j=t;
		}
		else break;
	}
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
