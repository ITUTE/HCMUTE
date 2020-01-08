#include <stdio.h>
#define size 1000

void nhapMang(int A[], int &n);
void leftShift(int A[], int n, int k);
//void delElement(int A[], int &n, int k);
void xuatMang(int A[], int n);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	int k;
	scanf("%d",&k);
	leftShift(A,n,k);
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

void leftShift(int A[], int nA, int k)
{
	int B[size],i,nB=0;
	int pos_leftShift=k;
	//int pos_rightShift=nA-k;
	for (i=pos_leftShift;i<nA;i++)
		B[nB++]=A[i];
	for (i=0;i<pos_leftShift;i++)
		B[nB++]=A[i];
	for (i=0;i<nA;i++)
		A[i]=B[i];
}

void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

/*
//C2
void delElement(int A[], int &n, int k)
{
	for (int i=k;i<n-1;i++)
		A[i]=A[i+1];
	n--;
}

void leftShift(int A[], int n, int k)
{
	int i,term;
	for (i=0;i<k;i++)
	{
		term=A[0];
		delElement(A,n,0);
		n++;
		A[n-1]=term;
	}
}
*/
