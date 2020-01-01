#include <stdio.h>
void Xuat(int A[], int n);
void QuickSort(int A[], int L, int R);
void swap(int &a, int &b);

int main()
{
	int A[]={3,5,1,2,4,8,0,7,9,6};
	int n=10;
	QuickSort(A,0,n-1);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void QuickSort(int A[], int L, int R)
{
	if (L<=R)
	{
		int M=(L+R)/2;
		int i=L, j=R;
		while (i<=j)
		{
			while (A[i]<A[M])	i++;
			while (A[j]>A[M])	j--;
			if (i<=j)
			{
				swap(A[i],A[j]);
				i++;
				j--;
			}
		}
		if (i<R)	QuickSort(A,i,R);
		if (L<j)	QuickSort(A,L,j);
	}
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
