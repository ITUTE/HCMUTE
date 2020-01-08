#include <stdio.h>
#define size 1000

void nhapMang(int A[], int &n);
void rightShift(int A[], int n, int k);
//void delElement(int A[], int &n, int k);
void xuatMang(int A[], int n);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	int k;
	scanf("%d",&k);
	rightShift(A,n,k);
	xuatMang(A,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void rightShift(int A[], int nA, int k)
{
	int B[size],i,nB=0;
	int pos_rightShift=nA-k;
	//int pos_leftShif=k;
	for (i=pos_rightShift;i<nA;i++)
		B[nB++]=A[i];
	for (i=0;i<pos_rightShift;i++)
		B[nB++]=A[i];
	for (i=0;i<nA;i++)
		A[i]=B[i];
}

void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
