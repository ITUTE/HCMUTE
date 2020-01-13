#include <stdio.h>
#define max 32000

void nhap(float A[], int &n);
int find(float A[], int n);
void xuat(float A[], int n);

int main()
{
	int n;
	float A[max];
	nhap(A,n);
	int pos=find(A,n);
	xuat(A,pos);
	return 0;
}

void nhap(float A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%f", &A[i]);
}

int find(float A[], int n)
{
	for (int i=n-1;i>=0;i--)
		if (A[i]>0) return i;
	//ko thay
	return -1;
}

void xuat(float A[], int pos)
{
	if (pos==-1) printf("%d",-1);
	else 
		printf("%f",A[pos]);
}
