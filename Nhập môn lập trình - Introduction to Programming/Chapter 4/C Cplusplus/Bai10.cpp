#include <stdio.h>
#define size 32000

void nhapMang(float A[], int &n);
void xuly(float A[], float B[], int n);
void xuat(float A[], float B[], int n);

int main()
{
	float A[size],B[size];
	int n;
	nhapMang(A,n);
	xuly(A,B,n);
	xuat(A,B,n);
	return 0;
}

void nhapMang(float A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%f",&A[i]);
}

void xuly(float A[], float B[], int n)
{
	if (A[0]*A[1]<0)
		B[0]=1;
	if (A[n-2]*A[n-1]<0)
		B[n-1]=1;
	for (int i=1;i<n-1;i++)
		if ((A[i]*A[i+1]<0)||(A[i]*A[i-1]<0))
			B[i]=1;
}

void xuat(float A[], float B[], int n)
{
	for (int i=0;i<n;i++)
		if (B[i]==1)
			printf("%f\t",A[i]);
}
