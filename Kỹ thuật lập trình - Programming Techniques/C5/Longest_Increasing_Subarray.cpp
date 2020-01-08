#include <stdio.h>
#include <limits.h>
#define SIZE 100

void nhap(int A[], int &n)
{
	scanf("%d",&n);
	n+=2;
	A[0]=-INT_MAX;	A[n-1]=INT_MAX;
	for (int i=1;i<n-1;i++)
		scanf("%d",&A[i]);
}

void Len_LIS(int A[], int n, int L[])
{
	for (int i=n-1;i>=0;i--)
	{
		L[i]=1;
		for (int j=i+1;j<=n;j++)
			if (A[j]>A[i] && L[i]<L[j]+1)
				L[i]=L[j]+1;
	}
}

void Trace(int A[], int n, int L[])
{
	int i=0;
	while (L[i]>2)
	{
		int j;
		for (j=i+1;j<=n;j++)
			if (L[j]==L[i]-1)
			{
				printf("%d ",A[j]);
				break;
			}
		i=j;
	}
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d\t",A[i]);
}

int main()
{
	int A[SIZE]={0}, L[SIZE]={0};
	int n;
	nhap(A,n);
	Len_LIS(A,n,L);
	Trace(A,n,L);
	return 0;
}
