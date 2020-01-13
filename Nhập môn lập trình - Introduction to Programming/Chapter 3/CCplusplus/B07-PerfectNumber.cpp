#include <stdio.h>
#define max 32000

void nhap(int A[], int &n);
void xuat(int kq);
int perfectNum(int x);
int count(int A[], int n);

int main()
{
	int n, A[max];
	nhap(A,n);
	int kq=count(A,n);
	xuat(kq);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

void xuat(int kq)
{
	printf("%d ", kq);
}

int perfectNum(int x)
{
	int sum=0;
	for (int i=1;i<x;i++)
		if (x%i==0) sum+=i;
	if (sum==x) 
		return 1;
	else return 0;
}

int count(int A[], int n)
{
	int sum=0;
	for (int i=0;i<n;i++)
		if (perfectNum(A[i])) sum+=1;
	return sum;
}
