#include <stdio.h>
#define max 32000
void nhap(float A[], int &n);
int increase(float A[], int n);
void xuat(int kq);

int main()
{
	int n;
	float A[max];
	nhap(A,n);
	int kq=increase(A,n);
	xuat(kq);
	return 0;
}

void nhap(float A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%f", &A[i]);
}

int increase(float A[], int n)
{
	for (int i=0;i<n-2;i++)
		if (A[i]>A[i+1]) return 0;
	return 1;
}

void xuat(int kq)
{
	if (kq)
		printf("Mang tang dan.");
	else printf("Mang ko thoa DK tang dan.");
}
