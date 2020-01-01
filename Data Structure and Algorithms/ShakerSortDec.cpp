#include <stdio.h>
void Xuat(int A[], int n);
void swap(int &a, int &b);
void ShakerSort(int A[], int n);

int main()
{
	int A[]={1,5,3,2,4,7,6,9,0,8};
	int n=10;
	ShakerSort(A,n);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void ShakerSort(int A[], int n)
{
	int L=0, R=n-1;
	int k=R;
	while (L<R)
	{
		for (int i=R; i>L;i--)
			if (A[i]>A[i-1])
			{
				swap(A[i],A[i-1]);
				k=i;
			}
		L=k;
		for (int i=L;i<R;i++)
			if (A[i]<A[i+1])
			{
				swap(A[i],A[i+1]);
				k=i;
			}
		R=k;
	}
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
