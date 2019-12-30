#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
int maxInArray(int A[], int n);
int countMax(int A[], int n, int max);
void xuat(int kq);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	int max=maxInArray(A,n);
	int kq=countMax(A,n,max);
	xuat(kq);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int maxInArray(int A[], int n)
{
	int max=A[0];
	for (int i=1;i<n;i++)
		if (A[i]>max)
			max=A[i];
	return max;
}

int countMax(int A[], int n,int max)
{
	int count=0;
	for (int i=0;i<n;i++)
		if (A[i]==max)
			count++;
	return count;
}

void xuat(int kq)
{
	printf("%d",kq);
}
