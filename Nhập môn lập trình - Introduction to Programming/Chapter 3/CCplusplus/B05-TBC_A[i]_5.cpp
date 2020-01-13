#include <stdio.h>
#define max 32000
void nhap(int A[], int &n);
float TBC(int A[], int n);
void xuat(float kq);

int main()
{
	int n, A[max];
	nhap(A,n);
	float kq=TBC(A,n);
	xuat(kq);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

float TBC(int A[], int n)
{
	float sum=0,count=0;
	for (int i=0;i<n;i++)
		if (A[i]%5==0)
		{
			count++;
			sum+=A[i];
		}
	return sum/count;
}

void xuat(float kq)
{
	printf("%f", kq);
}
