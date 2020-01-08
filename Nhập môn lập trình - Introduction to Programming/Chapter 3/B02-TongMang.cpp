#include <stdio.h>
#define max 32000

void nhap(float A[], int &n);
float sum(float A[], int n);
void xuat(float kq);

int main()
{
	int n;
	float A[max];
	nhap(A,n);
	float kq=sum(A,n);
	xuat(kq);
	return 0;
}

void nhap(float A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%f", &A[i]);
}

float sum(float A[], int n)
{
	float count=0;
	for (int i=0;i<n;i++)
		count+=A[i];
	return count;
}

void xuat(float kq)
{
	printf("%f", kq);
}
