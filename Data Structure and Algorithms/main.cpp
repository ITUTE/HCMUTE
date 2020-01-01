#include <stdio.h>

void Sort(int A[], int n);
void Xuat(int A[], int n);
void Swap(int A[], int i, int j);

int main()
{
	int A[]={1,6,9,2,4,0,3,5,7,8};
	int n=10;
	Sort(A,n);
	Xuat(A,n);
	return 0;
}
void Swap(int A[], int i, int j)
{
	int tmp=A[i];
	A[i]=A[j];
	A[j]=tmp;
}

void Sort(int A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (A[i]%2==0)
			{
				if (A[j]%2==0)
					if (A[j]<A[i])
						Swap(A,i,j);
			}
			else
			{
				if (A[j]%2!=0)
					if (A[j]>A[i])
						Swap(A,i,j);
			}
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
