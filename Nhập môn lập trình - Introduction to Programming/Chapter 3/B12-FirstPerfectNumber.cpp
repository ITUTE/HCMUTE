#include <stdio.h>
#define max 32000

void nhap(int A[], int &n);
void xuat(int A[], int pos);
int perfectNum(int x);
int find(int A[], int n);

int main()
{
	int n, A[max];
	nhap(A,n);
	int pos=find(A,n);
	xuat(A,pos);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

void xuat(int A[], int pos)
{
	if (pos==-1) printf("%d",pos);
	else
		printf("%d", A[pos]);
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

int find(int A[], int n)
{
	for (int i=0;i<n;i++)
		if (perfectNum(A[i])) return i;
	//ko thay
	return -1;
}
