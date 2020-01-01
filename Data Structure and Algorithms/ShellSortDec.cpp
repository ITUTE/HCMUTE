#include <stdio.h>
void Xuat(int A[], int n);
void ShellSort(int A[], int n);

int main()
{
	int A[]={1,7,3,6,4,8,2,0,9,5};
	int n=10;
	ShellSort(A,n);
	Xuat(A,n);
	return 0;
}

void Xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void ShellSort(int A[], int n)
{
	int k=1;
	while (2*k+1<n)
		k=2*k+1;
	while (k>0)
	{
		for (int i=k;i<n;i++)
		{
			int j=i;
			int x=A[i];
			while (j>=k && A[j-k]<x)
			{
				A[j]=A[j-k];
				j=j-k;
			}
			A[j]=x;
		}
		k=(k-1)/2;
	}
	
}
