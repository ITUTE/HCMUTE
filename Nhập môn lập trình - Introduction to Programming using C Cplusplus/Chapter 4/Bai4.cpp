/*
Tach A[] thanh 2 mang B[] và C[]
*/

#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &nA);
void xuatMang(int A[], int nA);
void tachMang(int A[], int B[], int C[], int nA, int &nB, int &nC);

int main()
{
	int A[size],B[size],C[size],nA;
	int nB,nC;
	nhapMang(A,nA);
	tachMang(A,B,C,nA,nB,nC);
	xuatMang(B,nB);
	printf("\n");
	xuatMang(C,nC);
	return 0;
}

void nhapMang(int A[], int &nA)
{
	scanf("%d",&nA);
	for (int i=0;i<nA;i++)
		scanf("%d",&A[i]);
}

void xuatMang(int A[],int nA)
{
	for (int i=0;i<nA;i++)
		printf("%d ",A[i]);
}

void tachMang(int A[], int B[], int C[], int nA, int &nB, int &nC)
{
	nB=0;nC=0;
	for (int i=0;i<nA;i++)
		if (A[i]>=0)
			B[nB++]=A[i];
		else
			C[nC++]=A[i];
}
