#include <stdio.h>
#define size 100

void nhapMang(int A[], int &n);
void addElements(int A[], int nA, int nB);
void xuly(int A[], int nA);
void xuatMang(int A[], int n);

int main()
{
	int A[size];
	int n;
	nhapMang(A,n);
	xuly(A,n);
	xuatMang(A,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuly(int A[], int nA)
{
	int i,nB=0;
	int B[size];
	for (i=0;i<nA;i++)
		if (A[i]%2==0&&A[i]!=0)
			B[nB++]=A[i];
	for (i=0;i<nA;i++)
		if (A[i]==0)
			B[nB++]=A[i];
	for (i=0;i<nA;i++)
		if (A[i]%2!=0)
			B[nB++]=A[i];
	for (i=0;i<nA;i++)
		A[i]=B[i];
}
void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}


