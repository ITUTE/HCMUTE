/*
Tim phan tu lon thu 2
*/

#include <stdio.h>
#include <limits.h>
#define size 32000

void nhapMang(int A[], int &n);
void xuat(int kq);
int find(int A[], int n);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	int kq=find(A,n);
	printf("%d",A[kq]);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuat(int kq)
{
	printf("%d",kq);
}

int find(int A[], int n)
{
	int max=0;
	int secondMax=1;
	for (int i=1;i<n;i++)
		if (A[i]>A[max])
		{
			secondMax=max;
			max=i;
		}
		else if (A[i]>A[secondMax] && A[i]<A[max])
			secondMax=i;
	return secondMax;
}
