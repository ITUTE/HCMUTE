#include <stdio.h>
void InsertionSort(int A[], int n);
void Xuat(int A[], int n);

int main()
{
	int A[]={9,1,7,2,3,0,5,8,6,4};
	int n=10;
	InsertionSort(A,n);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void InsertionSort(int A[], int n)
{
	for (int i=1;i<n;i++)
	{
		int x=A[i];
		int j=i-1;
		while (j>=0 && A[j]>x)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}
