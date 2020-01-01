#include <stdio.h>
#define SIZE 100
void swap(int &a, int &b);
void Xuat(int A[], int n);
void CreateHeap(int A[], int n);
void Heap(int A[], int i, int n);
void HeapSort(int A[], int n);
void PrintHeap(int A[], int n);
void Push(int A[], int &n, int value);

int main()
{
	//int A[]={5,3,6,1,9,2,4,0,8,7};
	int A[SIZE];
	int n=0;
	Push(A,n,23);
	Push(A,n,53);
	Push(A,n,78);
	Push(A,n,2);
	Push(A,n,13);
	Push(A,n,65);
	Push(A,n,10);
	HeapSort(A,n);
	Xuat(A,n);
	return 0;
}

void Push(int A[], int &n, int value)
{
	int i=n++;
	A[n]=value;
	while (i>=0&A[i/2]<A[i])
	{
		swap(A[i/2],A[i]);
		i/=2;
	}
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

void CreateHeap(int A[], int n)
{
	for (int i=n/2;i>=0;i--)
	{
		Heap(A,i,n);
		//PrintHeap(A,n);
	}
}

void HeapSort(int A[], int n)
{
	CreateHeap(A,n);
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
